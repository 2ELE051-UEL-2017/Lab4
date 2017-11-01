#include <string.h>
#include "CppUTest/TestHarness.h"

extern "C" {
	char* strcpy3(char* dst, const char* src);
}

TEST_GROUP(strcpy3)
{
};

static void testStrcpyApenasRetorno(char* dst, const char* src)
{
	POINTERS_EQUAL(dst, strcpy3(dst, src));
}

static void testStrcpyCompleto(char* dst, const char* src)
{
	testStrcpyApenasRetorno(dst, src);

	STRCMP_EQUAL(src, dst);
}

TEST(strcpy3, StringVaziaApenasRetorno)
{
	const char expected[] = "";
	char str[sizeof(expected)];

	testStrcpyApenasRetorno(str, expected);
}

TEST(strcpy3, StringVaziaCompleto)
{
	const char expected[] = "";
	char str[sizeof(expected)];

	testStrcpyCompleto(str, expected);
}

TEST(strcpy3, StringUmCaractere)
{
	const char expected[] = "a";
	char str[sizeof(expected)];

	testStrcpyCompleto(str, expected);
}

TEST(strcpy3, StringCincoCaracteres)
{
	const char expected[] = "abcde";
	char str[sizeof(expected)];

	testStrcpyCompleto(str, expected);
}

TEST(strcpy3, StringDezCaracteres)
{
	const char expected[] = "abcdefghij";
	char str[sizeof(expected)];

	testStrcpyCompleto(str, expected);
}