
#ifndef APPETIZER_UTIL_DEFINES_H_
#define APPETIZER_UTIL_DEFINES_H_

#include <stdint.h>
#include <float.h>


#define likely(x) __builtin_expect((x), 1)
#define unlikely(x) __builtin_expect((x), 0)

#ifndef   null
#define   null    0
#endif

typedef unsigned char   byte;
typedef unsigned short  ushort;
typedef unsigned int    uint;


#define GETTER(TYPE, VAR_NAME) \
		inline const TYPE VAR_NAME() const { return VAR_NAME##_; }

#define SETTER(TYPE, VAR_NAME) \
		inline void VAR_NAME(const TYPE value) { VAR_NAME##_ = value; }

#define GETTER_SETTER(TYPE, VAR_NAME)  \
		GETTER(TYPE, VAR_NAME) \
		SETTER(TYPE, VAR_NAME)


#define GETTER_FUNC(TYPE, VAR_NAME) \
		inline const TYPE VAR_NAME() const { return get_##VAR_NAME(); }

#define SETTER_FUNC(TYPE, VAR_NAME) \
		inline void VAR_NAME(const TYPE value) { set_##VAR_NAME(value); }

#define GETTER_SETTER_FUNC(TYPE, VAR_NAME)  \
		GETTER_FUNC(TYPE, VAR_NAME) \
		SETTER_FUNC(TYPE, VAR_NAME)


#define GETTER_WRAP(TYPE, VAR_NAME, MEMBER_NAME) \
		inline const TYPE VAR_NAME() const { return MEMBER_NAME##_.VAR_NAME(); }

#define SETTER_WRAP(TYPE, VAR_NAME, MEMBER_NAME) \
		inline void VAR_NAME(const TYPE value) { MEMBER_NAME##_.VAR_NAME(value); }

#define GETTER_SETTER_WRAP(TYPE, VAR_NAME, MEMBER_NAME)  \
		GETTER_WRAP(TYPE, VAR_NAME, MEMBER_NAME) \
		SETTER_WRAP(TYPE, VAR_NAME, MEMBER_NAME)


namespace bunnylang {
template <typename T>
struct ArrayDeleter {
	void operator () (T *p) {
		delete[] p;
	}
};

} // namespace bunnylang


#endif /* APPETIZER_UTIL_DEFINES_H_ */
