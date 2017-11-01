#include <string.h>
#include "CppUTest/TestHarness.h"
#include "auxTestFunctions.h"

extern "C" {
	char* strcat2(char* dst, const char* src);
}

TEST_GROUP(strcat2)
{
};

TEST(strcat2, StringVaziaComStringVazia)
{
	const char expected[] = "";
	char str1[sizeof(expected)] = "";
	const char str2[] = "";

	testStrcat(expected, str1, str2, strcat2);
}

TEST(strcat2, StringUmCaractereComStringVazia)
{
	const char expected[] = "a";
	char str1[sizeof(expected)] = "a";
	const char str2[] = "";

	testStrcat(expected, str1, str2, strcat2);
}

TEST(strcat2, StringVaziaComStringUmCaractere)
{
	const char expected[] = "a";
	char str1[sizeof(expected)] = "";
	const char str2[] = "a";

	testStrcat(expected, str1, str2, strcat2);
}

TEST(strcat2, StringUmCaractereComStringUmCaractere)
{
	const char expected[] = "aa";
	char str1[sizeof(expected)] = "a";
	const char str2[] = "a";

	testStrcat(expected, str1, str2, strcat2);
}

TEST(strcat2, StringCincoCaracteresComStringVazia)
{
	const char expected[] = "abcde";
	char str1[sizeof(expected)] = "abcde";
	const char str2[] = "";

	testStrcat(expected, str1, str2, strcat2);
}

TEST(strcat2, StringVaziaComStringCincoCaracteres)
{
	const char expected[] = "abcde";
	char str1[sizeof(expected)] = "";
	const char str2[] = "abcde";

	testStrcat(expected, str1, str2, strcat2);
}

TEST(strcat2, StringCincoCaracteresComStringQuatroCaracteres)
{
	const char expected[] = "abcdefghi";
	char str1[sizeof(expected)] = "abcde";
	const char str2[] = "fghi";

	testStrcat(expected, str1, str2, strcat2);
}
