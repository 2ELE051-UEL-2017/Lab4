#include <string.h>
#include "CppUTest/TestHarness.h"
#include "auxTestFunctions.h"

extern "C" {
	char* strcpy2(char* dst, const char* src);
}

TEST_GROUP(strcpy2)
{
};

TEST(strcpy2, StringVaziaApenasRetorno)
{
	const char expected[] = "";
	char str[sizeof(expected)];
	
	testStrcpyApenasRetorno(str, expected, strcpy2);
}

TEST(strcpy2, StringVaziaCompleto)
{
	const char expected[] = "";
	char str[sizeof(expected)];

	testStrcpyCompleto(str, expected, strcpy2);
}

TEST(strcpy2, StringUmCaractere)
{
	const char expected[] = "a";
	char str[sizeof(expected)];

	testStrcpyCompleto(str, expected, strcpy2);
}

TEST(strcpy2, StringCincoCaracteres)
{
	const char expected[] = "abcde";
	char str[sizeof(expected)];

	testStrcpyCompleto(str, expected, strcpy2);
}

TEST(strcpy2, StringDezCaracteres)
{
	const char expected[] = "abcdefghij";
	char str[sizeof(expected)];

	testStrcpyCompleto(str, expected, strcpy2);
}