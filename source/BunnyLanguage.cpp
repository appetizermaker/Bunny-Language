
#include "defines.h"
#include "BunnyLanguage.h"

#include <fstream>
#include <iostream>

namespace bunny_language {


BunnyLanguage::BunnyLanguage()
{

}

BunnyLanguage::~BunnyLanguage()
{
}

/// 파일을 읽고 해석하여, 실행함
int BunnyLanguage::run(const string &filePath)
{
	/*
	std::ifstream fin;
	fin.open(filePath.c_str());
	if (!fin)
		return -1;

	// 소스 코드를 한 라인씩 읽어서 내부 코드 생성
	char line[256];
	vector<char> interCode;
	while (fin.eof() == false)
	{
		fin.getline(line, 256);
		lexer_.lexicalAnalysis(line, interCode);
	}

	fin.close();
	*/
	return 0;
}


} /* namespace appetizer */





























