/*
 * integer.h
 *
 *  Created on: 2013. 9. 19.
 *      Author: john
 */

#ifndef INTEGER_H_
#define INTEGER_H_

#include <stdio.h>
#include "object.h"


namespace bunnylang {
class Integer : public Object {
	// field
private:
	int value_;


	// method
public:
	Integer(int value = 0) : value_(value) {
	}

	operator int() const {
		return value_;
	}

	int operator -() const {
		return -value_;
	}

	int operator =(int rhs) {
		value_ = rhs;
		return value_;
	}

	int operator +=(int rhs) {
		value_ += rhs;
		return value_;
	}

	int operator -=(int rhs) {
		value_ -= rhs;
		return value_;
	}

	int operator *=(int rhs) {
		value_ *= rhs;
		return value_;
	}

	int operator /=(int rhs) {
		value_ /= rhs;
		return value_;
	}

	int toInt() {
		return value_;
	}
	float toFloat() {
		return (float)value_;
	}
	double toDouble() {
		return (double)value_;
	}
	string toString() {
		char s[10];
		snprintf(s, 9, "%d", value_);
		string str = s;
		return str;
	}


	// getter / setter
public:
	GETTER_SETTER(int, value)
};


int operator +(const Integer& lhs, int rhs) {
	return lhs.value() + rhs;
}

int operator -(const Integer& lhs, int rhs) {
	return lhs.value() - rhs;
}

int operator *(const Integer& lhs, int rhs) {
	return lhs.value() * rhs;
}

int operator /(const Integer& lhs, int rhs) {
	return lhs.value() / rhs;
}


} /* namespace bunnylang */
#endif /* INTEGER_H_ */














