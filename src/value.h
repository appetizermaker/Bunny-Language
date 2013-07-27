#ifndef VALUE_H_
#define VALUE_H_

#include <algorithm>
#include <initializer_list>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "defines.h"
#include "object.h"


namespace bunnylang {

class Array;
class Class;
class Dictionary;
class Function;
class Instance;
class Null;
class String;
class Thread;
class Value;

using std::find;
using std::initializer_list;
using std::shared_ptr;
using std::string;
using std::unordered_map;
using std::vector;

class Value {
public:
  enum DataType {
    TYPE_NULL,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_BOOL,
    TYPE_STRING,
    TYPE_FUNCTION,
    TYPE_ARRAY,
    TYPE_DICTIONARY,
    TYPE_CLASS,
    TYPE_INSTANCE,
  };

  // field
private:
  DataType type_;
  union Data {
    int     int_value;
    float   float_value;
    double  double_value;
    bool    bool_value;
    int64_t int_64_value;   ///< for equal check
  }data_;
  shared_ptr<Object> object_value_;

  // method
public:
  Value();
  Value(Null value);
  Value(int value);
  Value(float value);
  Value(double value);
  Value(bool value);
  Value(const char *value);
  Value(const string &value);
  Value(const shared_ptr<String> &value);
  Value(const shared_ptr<Function> &value);
  Value(const shared_ptr<Array> &value);
  Value(const shared_ptr<Dictionary> &value);
  Value(const shared_ptr<Class> &value);
  Value(const shared_ptr<Instance> &value);
  ~Value();

  Value Call(const initializer_list<Value> &params);
  void Print();

  Value operator = (Null value);
  Value operator = (int value);
  Value operator = (float value);
  Value operator = (double value);
  Value operator = (bool value);
  Value operator = (const char *value);
  Value operator = (const string &value);
  Value operator = (const shared_ptr<String> &value);
  Value operator = (const shared_ptr<Function> &value);
  Value operator = (const shared_ptr<Array> &value);
  Value operator = (const shared_ptr<Dictionary> &value);
  Value operator = (const shared_ptr<Class> &value);
  Value operator = (const shared_ptr<Instance> &value);

  bool operator == (const Value &value) const {
    return this->type_ == value.type_ &&
        this->data_.int_64_value == value.data_.int_64_value &&
        this->object_value_.get() == value.object_value_.get();
  }

  // getter/setter
public:
  GETTER(DataType, type)
  inline int int_value() const       { return data_.int_value; }
  inline float float_value() const   { return data_.float_value; }
  inline double double_value() const { return data_.double_value; }
  inline bool bool_value() const     { return data_.bool_value; }
  GETTER(shared_ptr<Object>&, object_value)
};


class Null : public Object {
};
extern Null null_value;


class String : public Object {
  // field
private:
  string value_;

  // method
public:
  String () {
  }

  String(const string &value)
      : value_(value) {
  }

  String(const char *value)
      : value_(value) {
  }

  // getter/setter
public:
  GETTER_SETTER(string&, value)
};


class Function : public Object {
  // field
private:

  // method
public:
  virtual ~Function() {
  }

  virtual Value operator () (const initializer_list<Value> &params) = 0;
  virtual string name() = 0;
  virtual int param_count() = 0;

  // getter/setter
public:
};


class Array : public Object {
  // field
private:
  vector<Value> values_;

  // method
public:
  Value& operator [] (int idx) {
    return values_[idx];
  }

  const Value& operator [] (int idx) const {
    return values_[idx];
  }

  int size() {
    return (int)values_.size();
  }

  // getter/setter
public:
  inline vector<Value>& values() {
    return values_;
  }
};


class Dictionary : public Object {
  // field
private:
  unordered_map<Value, Value> map_;

  // method
public:
  Value& operator [] (const Value &key) {
    return map_[key];
  }

  bool HasValue(const Value &key) {
    return map_.find(key) != map_.end();
  }

  // getter/setter
public:
};


class Class : public Object {
  // field
private:
  shared_ptr<Class> base_;
  unordered_map<string, int> var_idx_map_;
  int var_count_;

  // method
public:
  Class()
      : var_count_(0) {
  }
  virtual ~Class() {}

  void ConstructVars(vector<Value> &vars);
  void AddVars(vector<Value> &vars);
  virtual void InitVars(vector<Value> &vars) {}
  virtual string name() = 0;

  // getter/setter
public:
  GETTER(shared_ptr<Class>&, base)
};


class Instance : public Object {
  // field
private:
  shared_ptr<Class>  class_;
  vector<Value> vars_;

  // method
public:
  Instance(const shared_ptr<Class> &class_value) {
    class_ = class_value;
    class_->ConstructVars(vars_);
  }

  // getter/setter
public:
  inline const shared_ptr<Class>& GetClass() {
    return class_;
  }
};


} /* namespace bunnylang */


#endif /* VALUE_H_ */
