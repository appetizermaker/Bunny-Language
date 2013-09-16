
#include <iostream>

#include "value.h"
#include "thread.h"


using namespace std;
using namespace bunnylang;



class TestFunc : public Function {
	Value operator () (const std::initializer_list<Value> &params) {
		//    const Value *p = params.begin();
		//    return p[0] + p[1];
		cout << "test function called!!!!" << endl;
		return null_value;
	}
	std::string name() { return "TestFunc()"; }
	int param_count()  { return 2; }
};

int main() {
	cout << "test start" << endl;

	Value f = shared_ptr<Function>(new TestFunc);
	f.Call({});

	Value arr = shared_ptr<Array>(new Array);
	shared_ptr<Array> a = dynamic_pointer_cast<Array>(arr.object_value());
	for (Value &v : a->values()) {
		v = 10;
	}

	cout << "test end" << endl;

	return 0;
}


class CoroutineTest {
	int label_idx_;
	bool is_yield_;

	int resume_input_;

	int sub(int param0) {
		return 0;
	}

	int func(int param0, int param1) {
		int result;
		is_yield_ = false;
		switch(label_idx_) {
		case 0: break;
		case 1: goto Label1;
		case 2: goto Label2;
		case 3: goto Label3;
		}

		int a;
		int b;

		a = 0;
		a = 4;

		// a = yield(3)
    		label_idx_ = 1;
    		is_yield_ = true;
    		return 3;
    		Label1:
    		a = resume_input_;
    		// end of yield


    		// a = sub(30)
    		label_idx_ = 2;
    		Label2:
    		result = sub(30);
    		if (is_yield_ == true)
    			return result;
    		else
    			a = result;
    		// end of call sub


    		b = 0;
    		b = 8;

    		// b = yield(10)
    		label_idx_ = 3;
    		is_yield_ = true;
    		return 10;
    		Label3:
    		b = resume_input_;
    		// end of yield

	}
};
















