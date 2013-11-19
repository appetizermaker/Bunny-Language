/*
 * var.h
 *
 *  Created on: 2013. 9. 20.
 *      Author: john
 */

#ifndef VAR_H_
#define VAR_H_

#include <memory>
#include <stdio.h>
#include "object.h"


namespace bunnylang {

using std::shared_ptr;


class Var {
	// field
private:
	shared_ptr<Object> value_;


	// method
public:
	Var();


	// getter / setter
public:
	GETTER_SETTER(shared_ptr<Object>&, value)
};

} /* namespace bunnylang */
#endif /* VAR_H_ */













