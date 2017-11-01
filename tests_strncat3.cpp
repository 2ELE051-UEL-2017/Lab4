#include <string.h>
#include "CppUTest/TestHarness.h"
#include "auxTestFunctions.h"

extern "C" {
	char* strncat3(char* dst, const char* src, size_t num);
}

TEST_GROUP(strncat3)
{
};

TEST(strncat3, StringVaziaComStringVaziaNum0)
{
	const char expected[] = "";
	char str1[sizeof(expected)] = "";
	const char str2[] = "";

	testStrncat(expected, str1, str2, 0, strncat3);
}

TEST(strncat3, StringUmCaractereComStringVaziaNum0)
{
	const char expected[] = "a";
	char str1[sizeof(expected)] = "a";
	const char str2[] = "";

	testStrncat(expected, str1, str2, 0, strncat3);
}

TEST(strncat3, StringUmCaractereComStringVaziaNum1)
{
	const char expected[] = "a";
	char str1[sizeof(expected)] = "a";
	const char str2[] = "";

	testStrncat(expected, str1, str2, 1, strncat3);
}

TEST(strncat3, StringVaziaComStringUmCaractereNum1)
{
	const char expected[] = "a";
	char str1[sizeof(expected)] = "";
	const char str2[] = "a";

	testStrncat(expected, str1, str2, 1, strncat3);
}

TEST(strncat3, StringVaziaComStringUmCaractereNum0)
{
	const char expected[] = "";
	char str1[sizeof(expected)] = "";
	const char str2[] = "a";

	testStrncat(expected, str1, str2, 0, strncat3);
}

TEST(strncat3, StringUmCaractereComStringUmCaractereNum1)
{
	const char expected[] = "aa";
	char str1[sizeof(expected)] = "a";
	const char str2[] = "a";

	testStrncat(expected, str1, str2, 1, strncat3);
}

TEST(strncat3, StringUmCaractereComStringUmCaractereNum0)
{
	const char expected[] = "a";
	char str1[sizeof(expected)] = "a";
	const char str2[] = "a";

	testStrncat(expected, str1, str2, 0, strncat3);
}

TEST(strncat3, StringCincoCaracteresComStringVaziaNum0)
{
	const char expected[] = "abcde";
	char str1[sizeof(expected)] = "abcde";
	const char str2[] = "";

	testStrncat(expected, str1, str2, 0, strncat3);
}


TEST(strncat3, StringVaziaComStringCincoCaracteresNum5)
{
	const char expected[] = "abcde";
	char str1[sizeof(expected)] = "";
	const char str2[] = "abcde";

	testStrncat(expected, str1, str2, 5, strncat3);
}

TEST(strncat3, StringVaziaComStringCincoCaracteresNum3)
{
	const char expected[] = "abc";
	char str1[sizeof(expected)] = "";
	const char str2[] = "abcde";

	testStrncat(expected, str1, str2, 3, strncat3);
}

TEST(strncat3, StringCincoCaracteresComStringQuatroCaracteresNum4)
{
	const char expected[] = "abcdefghi";
	char str1[sizeof(expected)] = "abcde";
	const char str2[] = "fghi";

	testStrncat(expected, str1, str2, 4, strncat3);
}

TEST(strncat3, StringCincoCaracteresComStringQuatroCaracteresNum10)
{
	const char expected[] = "abcdefghi";
	char str1[sizeof(expected)] = "abcde";
	const char str2[] = "fghi";

	testStrncat(expected, str1, str2, 10, strncat3);
}
TEST(strncat3, StringCincoCaracteresComStringQuatroCaracteresNum1)
{
	const char expected[] = "abcdef";
	char str1[sizeof(expected)] = "abcde";
	const char str2[] = "fghi";

	testStrncat(expected, str1, str2, 1, strncat3);
}