#ifndef THREAD_H_
#define THREAD_H_

#include <vector>

#include "object.h"
#include "value.h"


namespace bunnylang {

class Thread : public Object {
	// field
private:
	vector<Value> stack_;		///< func, start_lable, params, local vars
	vector<int> start_stack_idx_;


	// method
public:
	Thread();
	~Thread();

	// getter/setter
public:
};

} /* namespace bunnylang */
#endif /* THREAD_H_ */
