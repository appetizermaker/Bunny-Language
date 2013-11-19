/*
 * string.cpp
 *
 *  Created on: 2013. 9. 20.
 *      Author: john
 */

#include "string.h"

namespace bunnylang {

String::String() {
}

String::String(const string& str) : value_(str) {
}

String::String(const char* str) : value_(str) {
}

} /* namespace bunnylang */
