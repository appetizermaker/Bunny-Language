
#include "../defines.h"
#include "Lexer.h"

#include <iostream>


namespace bunny_language
{


Lexer::Lexer()
: cursor_(null)
{
	// 문자 종류표 초기화
	initCharTypeTable();

	// 예약어 초기화
	initReservedTokenMap();
}

Lexer::~Lexer()
{
}


void Lexer::initCharTypeTable()
{
	// 문자 종류표 초기화
	chType_.resize(256);
	for (uint i=0; i<chType_.size(); ++i)	chType_[i] = OTHERS;
	for (int i='0'; i<='9'; ++i)			chType_[i] = DIGIT;
	for (int i='A'; i<='Z'; ++i)			chType_[i] = LETTER;
	for (int i='a'; i<='z'; ++i)			chType_[i] = LETTER;
	chType_['_'] = LETTER;
	chType_[' '] = SPACE;
	chType_['\''] = Q_MARK;
	chType_['\"'] = Q_MARK;
	chType_['\\'] = ESCAPE;
}

void Lexer::initReservedTokenMap()
{
	// 예약어 초기화
	reservedToken_["+"] =			Token::PLUS;
	reservedToken_["-"] =			Token::MINUS;
	reservedToken_["*"] =			Token::MULTIPLY;
	reservedToken_["/"] =			Token::DIVISION;
	reservedToken_["%"] =			Token::MODULAR_OP;
	reservedToken_["+="] =			Token::PLUS_EQ;
	reservedToken_["-="] =			Token::MINUS_EQ;
	reservedToken_["*="] =			Token::MULTIPLY_EQ;
	reservedToken_["/="] =			Token::DIVISION_EQ;
	reservedToken_["%="] =			Token::MODULAR_OP_EQ;
	reservedToken_["="] =			Token::ASSIGN;
	reservedToken_["<"] =			Token::LESS;
	reservedToken_[">"] =			Token::GREATER;
	reservedToken_["<="] =			Token::LESS_EQ;
	reservedToken_[">="] =			Token::GREATER_EQ;
	reservedToken_["=="] =			Token::EQUAL;
	reservedToken_["!="] =			Token::NOT_EQUAL;
	reservedToken_["<<"] =			Token::L_SHIFT;
	reservedToken_[">>"] =			Token::R_SHIFT;
	reservedToken_["\'"] =			Token::SINGLE_Q;
	reservedToken_["\""] =			Token::DOUBLE_Q;
	reservedToken_["("] =			Token::L_PAREN;
	reservedToken_[")"] =			Token::R_PAREN;
	reservedToken_["{"] =			Token::L_BRACE;
	reservedToken_["}"] =			Token::R_BRACE;
	reservedToken_["."] =			Token::DOT;
	reservedToken_[","] =			Token::COMMA;
	reservedToken_["&"] =			Token::BIT_AND;
	reservedToken_["|"] =			Token::BIT_OR;
	reservedToken_["&&"] =			Token::AND;
	reservedToken_["||"] =			Token::OR;
	reservedToken_["^"] =			Token::BIT_XOR;
	reservedToken_["!"] =			Token::NOT;
	reservedToken_["~"] =			Token::BIT_NOT;
	reservedToken_["\n"] =			Token::NEW_LINE;
	reservedToken_[""] =			Token::NEW_LINE;
	reservedToken_["\t"] =			Token::TAB;
	reservedToken_["if"] =			Token::IF;
	reservedToken_["elif"] =		Token::ELIF;
	reservedToken_["else"] =		Token::ELSE;
	reservedToken_["while"] =		Token::WHILE;
	reservedToken_["for"] =			Token::FOR;
	reservedToken_["break"] =		Token::BREAK;
	reservedToken_["continue"] =	Token::CONTINUE;
	reservedToken_["int"] =			Token::INT;
	reservedToken_["float"] =		Token::FLOAT;
	reservedToken_["bool"] =		Token::BOOL;
	reservedToken_["string"] =		Token::STRING;
	reservedToken_["var"] =			Token::VAR;
	reservedToken_["function"] =	Token::FUNCTION;
	reservedToken_["return"] =		Token::RETURN;
}

bool Lexer::extractNextWord(string &word)
{
	word = "";

	if (unlikely(cursor_ == null))
		return false;

	char ch = getNextChar();

	// 공백 넘기기
	while (chType_[ch] == SPACE)
		ch = getNextChar();


	// 종류별로 대처
	switch (chType_[ch])
	{
	case Q_MARK:
		word += ch;

		// 따옴표 닫힐 때 까지
		for (ch=getNextChar(); chType_[ch]!=Q_MARK && ch!=0; ch=getNextChar())
		{
			word += ch;

			// escape 문자가 나온 경우 하나를 더 읽는다
			if (chType_[ch] == ESCAPE)
				word += getNextChar();
		}
		if (unlikely(ch == 0))
			getPreChar();
		else
			word += ch;
		break;

	case LETTER:
	case DIGIT:
		// 문자나 숫자가 나올때 까지 추가
		for (; chType_[ch] == LETTER || chType_[ch] == DIGIT; ch=getNextChar())
		{
			word += ch;
		}
		getPreChar();
		break;

	default:
		if (unlikely(ch == 0))
			return false;
		else
			word += ch;
		break;
	}

	return true;
}

/// 단순히 토큰화만 시킨다
void Lexer::tokenize(const char *source, vector<string> &tokenList)
{
	cursor_ = source;

	// 한단어씩 얻어와 추가
	string word;
	while (extractNextWord(word))
	{
		tokenList.push_back(word);
	}

	tokenList.push_back("\n");
}

#include <stdio.h>
/// 어휘 분석.. 소스 코드를 기호화 하여 내부 코드 생성
bool Lexer::lexicalAnalysis(const char *source, vector<char>& internalCode)
{
	// 토큰열을 만든다
	vector<string> tokenList;
	tokenize(source, tokenList);

	FILE *fp;
	fp = fopen("test.txt", "ab");
	for (uint i=0; i<tokenList.size(); ++i)
	{
		fprintf(fp, " %s", tokenList[i].c_str());
	}
	fclose(fp);

	// 내부 코드 생성


	return true;
}



} /* namespace bunny_language */
































