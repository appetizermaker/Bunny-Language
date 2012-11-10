
#ifndef TOKEN_H_
#define TOKEN_H_

#include <EASTL/string.h>


using namespace eastl;

namespace bunny_language
{

	/**
	 * @author JongHeon Kim
	 * @date 2012. 11. 9.
	 * @brief 하나의 토큰 정보
	 */
	struct Token
	{
		enum Type
		{
			NEW_LINE		= 0,
			TAB,
			L_PAREN,		R_PAREN,		L_BRACE,		R_BRACE,
			PLUS,			MINUS,			MULTIPLY,		DIVISION,		MODULAR_OP,
			PLUS_EQ,		MINUS_EQ,		MULTIPLY_EQ,	DIVISION_EQ,	MODULAR_OP_EQ,
			ASSIGN,			DOT,			COMMA,			SINGLE_Q,		DOUBLE_Q,
			EQUAL,			NOT_EQUAL,
			L_SHIFT,		R_SHIFT,
			LESS,			LESS_EQ,		GREATER,		GREATER_EQ,
			AND,			OR,				NOT,
			BIT_AND,		BIT_OR,			BIT_XOR,		BIT_NOT,
			IF,				ELIF,			ELSE,
			WHILE,			FOR,			CONTINUE,		BREAK,
			INT,			FLOAT,			BOOL,			STRING,			VAR,
			FUNCTION,		RETURN,
			IDENT,			CONST_INT,		CONST_STRING,
			OTHERS,
			END_LIST
		};

		Type type_;
	};

}
#endif /* TOKEN_H_ */
