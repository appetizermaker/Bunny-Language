#ifndef OBJECT_H_
#define OBJECT_H_

#include <string>
#include "../defines.h"


namespace bunnylang {

using std::string;


class Object {
public:
	virtual ~Object() {};

	virtual int toInt() = 0;
	virtual float toFloat() = 0;
	virtual double toDouble() = 0;
	virtual string toString() = 0;

	operator int () {
		return toInt();
	}
	operator float () {
		return toFloat();
	}
	operator double () {
		return toDouble();
	}
	operator string () {
		return toString();
	}
};

} /* namespace bunnylang */
#endif /* OBJECT_H_ */
