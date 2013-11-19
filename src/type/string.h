/*
 * string.h
 *
 *  Created on: 2013. 9. 20.
 *      Author: john
 */

#ifndef STRING_H_
#define STRING_H_

#include "object.h"


namespace bunnylang {

class String : public Object {
	// field
private:
	string value_;


	// method
public:
	String();
	String(const string &str);
	String(const char *str);

	operator const string& () {
		return value_;
	}

	int toInt() {
		return 0;
	}
	float toFloat() {
		return 0.f;
	}
	double toDouble() {
		return 0.;
	}
	string toString() {
		return value_;
	}


	// getter / setter
public:
	GETTER_SETTER(string&, value)
};

} /* namespace bunnylang */
#endif /* STRING_H_ */















