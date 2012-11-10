
#ifndef KEYWORD_H_
#define KEYWORD_H_

#include <EASTL/string.h>

#include "Token.h"


using namespace eastl;

namespace bunny_language
{

	/**
	 * @author JongHeon Kim
	 * @date 2012. 11. 9.
	 * @brief 토큰화 하는데 필요한 키워드 정보를 담는다
	 */
	struct KeyWord
	{
		string name_;
		Token::Type type_;

		inline void set(const string &name, Token::Type type)
		{
			name_ = name;
			type_ = type;
		}
	};
}
#endif /* KEYWORD_H_ */
