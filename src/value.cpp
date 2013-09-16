#include "value.h"

#include <iostream>

#include "thread.h"


namespace bunnylang {

Null null_value;

using std::cout;
using std::dynamic_pointer_cast;

Value::Value()
: type_(TYPE_NULL) {
}

Value::Value(Null value) {
	operator = (value);
}

Value::Value(int value) {
	operator = (value);
}

Value::Value(float value) {
	operator = (value);
}

Value::Value(double value) {
	operator = (value);
}

Value::Value(bool value) {
	operator = (value);
}

Value::Value(const char* value) {
	operator = (value);
}

Value::Value(const string& value) {
	operator = (value);
}

Value::Value(const shared_ptr<String>& value) {
	operator = (value);
}

Value::Value(const shared_ptr<Function>& value) {
	operator = (value);
}

Value::Value(const shared_ptr<Array>& value) {
	operator = (value);
}

Value::Value(const shared_ptr<Dictionary>& value) {
	operator = (value);
}

Value::Value(const shared_ptr<Class>& value) {
	operator = (value);
}

Value::Value(const shared_ptr<Instance>& value) {
	operator = (value);
}

Value::~Value() {
}

void Value::Print() {
	switch (type_) {
	case TYPE_ARRAY:      cout << "array";                       break;
	case TYPE_BOOL:       cout << data_.bool_value;              break;
	case TYPE_CLASS:      cout << "class : "
			<< dynamic_pointer_cast<Class>(object_value_)->name();    break;
	case TYPE_DICTIONARY: cout << "dictionary";                  break;
	case TYPE_DOUBLE:     cout << data_.double_value;            break;
	case TYPE_FLOAT:      cout << data_.float_value;             break;
	case TYPE_FUNCTION:   cout << "function : "
			<< dynamic_pointer_cast<Function>(object_value_)->name(); break;
	case TYPE_INSTANCE:   cout << "object";                      break;
	case TYPE_INT:        cout << data_.int_value;               break;
	case TYPE_NULL:       cout << "null";                        break;
	case TYPE_STRING:     cout
	<< dynamic_pointer_cast<String>(object_value_)->value();  break;
	}
}

Value Value::operator =(Null value) {
	type_ = TYPE_NULL;
	object_value_ = null;
	return *this;
}

Value Value::operator =(int value) {
	type_ = TYPE_INT;
	data_.int_value = value;
	object_value_ = null;
	return *this;
}

Value Value::operator =(float value) {
	type_ = TYPE_FLOAT;
	data_.float_value = value;
	object_value_ = null;
	return *this;
}

Value Value::operator =(double value) {
	type_ = TYPE_DOUBLE;
	data_.double_value = value;
	object_value_ = null;
	return *this;
}

Value Value::operator =(bool value) {
	type_ = TYPE_BOOL;
	data_.bool_value = value;
	object_value_ = null;
	return *this;
}

Value Value::operator =(const shared_ptr<String> &value) {
	type_ = TYPE_STRING;
	data_.int_value = 0;
	object_value_ = value;
	return *this;
}

Value Value::operator =(const shared_ptr<Function> &value) {
	type_ = TYPE_FUNCTION;
	data_.int_value = 0;
	object_value_ = value;
	return *this;
}

Value Value::operator =(const shared_ptr<Array> &value) {
	type_ = TYPE_ARRAY;
	data_.int_value = 0;
	object_value_ = value;
	return *this;
}

Value Value::operator =(const shared_ptr<Dictionary> &value) {
	type_ = TYPE_DICTIONARY;
	data_.int_value = 0;
	object_value_ = value;
	return *this;
}

Value Value::operator =(const shared_ptr<Class> &value) {
	type_ = TYPE_CLASS;
	data_.int_value = 0;
	object_value_ = value;
	return *this;
}

Value Value::operator =(const char* value) {
	return operator =(shared_ptr<String>(new String(value)));
}

Value Value::operator =(const string& value) {
	return operator =(shared_ptr<String>(new String(value)));
}

Value Value::Call(const initializer_list<Value> &params) {
	if (unlikely(type_ != TYPE_FUNCTION))
		return null_value;

	shared_ptr<Function> func_value =
			dynamic_pointer_cast<Function>(object_value_);

	return (*func_value)(params);
}

Value Value::operator =(const shared_ptr<Instance>& value) {
	type_ = TYPE_INSTANCE;
	object_value_ = value;
	return *this;
}


void Class::ConstructVars(vector<Value>& vars) {
	if (base_.get() != null)
		base_->ConstructVars(vars);

	AddVars(vars);
	InitVars(vars);
}

void Class::AddVars(vector<Value>& vars) {
	for (int i=0; i<var_count_; ++i)
		vars.push_back(null_value);
}


}
/* namespace bunnylang */




















