

#ifndef BUNNYLANGUAGE_H_
#define BUNNYLANGUAGE_H_

#include <EASTL/string.h>
#include <EASTL/vector.h>

#include "token/Lexer.h"


using namespace eastl;

namespace bunny_language {

	/**
	 * @author 김종헌
	 * @date 2012.11.09
	 * @brief 버니 언어 최상위 클래스
	 */
	class BunnyLanguage
	{
		// 멤버 변수
	private:
		Lexer lexer_;


		// 멤버 함수
	public:
		/// 생성/소멸자
		BunnyLanguage();
		~BunnyLanguage();

		/// 파일을 읽고 해석하여, 실행함
		int run(const string &filePath);
	};

} /* namespace bunny_language */
#endif /* BUNNYLANGUAGE_H_ */
