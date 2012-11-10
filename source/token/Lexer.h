
#ifndef LEXER_H_
#define LEXER_H_

#include <EASTL/hash_map.h>
#include <EASTL/vector.h>

#include "Token.h"


namespace bunny_language
{

	/**
	 * @author JongHeon Kim
	 * @date 2012. 11. 9.
	 * @brief 토큰화 시켜주는 어휘 분석기
	 */
	class Lexer
	{
	public:
		enum CharacterType
		{
			LETTER,
			DIGIT,
			SPACE,			///< 구분자이며, 미포함
			Q_MARK,			///< 따옴표.. 내부의 SPACE를 무시
			ESCAPE,			///< 따옴표 내부에서 작동하는 escape 문자
			OTHERS			///< 구분자
		};

		// 멤버 변수
	private:
		vector<CharacterType>			chType_;			///< 문자 종류 표
		hash_map<string, Token::Type>	reservedToken_;		///< 예약어 토큰

		const char *cursor_;				///< 현재 토큰화 할 지점.. no free


		// 멤버 함수
	private:
		inline char getNextChar()
		{
			char ch = *cursor_;
			++cursor_;
			return ch;
		}

		inline char getPreChar()
		{
			return *(--cursor_);
		}

		void initCharTypeTable();
		void initReservedTokenMap();
		bool extractNextWord(string &word);

		/// 단순히 토큰화만 시킨다
		void tokenize(const char *source, vector<string> &tokenList);

	public:
		/// 생성/ 소멸자
		Lexer();
		~Lexer();

		/// 어휘 분석.. 소스 코드를 기호화 하여 내부 코드 생성
		bool lexicalAnalysis(const char *source, vector<char> &internalCode);


		// 접근
	public:
	};


} /* namespace bunny_language */
#endif /* LEXER_H_ */
