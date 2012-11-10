/*
 * defines.h
 *
 *  Created on: 2012. 11. 9.
 *      Author: JongHeon Kim
 */

#ifndef DEFINES_H_
#define DEFINES_H_

#define likely(x) __builtin_expect((x), 1)
#define unlikely(x) __builtin_expect((x), 0)

#define null		0

// getter setter
#define GETTER(varType, funcName, varName)	\
			inline varType get##funcName() const {	return varName;	}
#define SETTER(varType, funcName, varName)	\
			inline void set##funcName(varType value) {	varName = value;	}
#define GETTER_SETTER(varType, funcName, varName)	\
			GETTER(varType, funcName, varName)	\
			SETTER(varType, funcName, varName)

// getter setter const ref
#define GETTER_CONST_REF(varType, funcName, varName)	\
			inline const varType& get##funcName() const {	return varName;	}
#define SETTER_CONST_REF(varType, funcName, varName)	\
			inline void set##funcName(const varType &value) {	varName = value;	}
#define GETTER_SETTER_CONST_REF(varType, funcName, varName)		\
			GETTER_CONST_REF(varType, funcName, varName)	\
			SETTER_CONST_REF(varType, funcName, varName)

// getter setter ref
#define GETTER_REF(varType, funcName, varName)	\
			inline varType& get##funcName() {	return varName;	}
#define GETTER_SETTER_REF(varType, funcName, varName)		\
			GETTER_REF(varType, funcName, varName)	\
			SETTER_CONST_REF(varType, funcName, varName)


typedef unsigned char byte;
typedef unsigned int uint;


#endif /* DEFINES_H_ */
