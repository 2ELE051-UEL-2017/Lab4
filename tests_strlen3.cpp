#include <string.h>
#include "CppUTest/TestHarness.h"

extern "C" {
	size_t strlen3(const char* str);
}

TEST_GROUP(strlen3)
{
};

TEST(strlen3, StringVazia)
{
	LONGS_EQUAL(strlen(""), strlen3(""));
}

TEST(strlen3, StringUmCaractere)
{
	LONGS_EQUAL(strlen("a"), strlen3("a"))
}

TEST(strlen3, StringDoisCaracteres)
{
	LONGS_EQUAL(strlen("ab"), strlen3("ab"))
}

TEST(strlen3, StringCincoCaracteres)
{
	LONGS_EQUAL(strlen("abcd "), strlen3("abcd "))
}

TEST(strlen3, StringDezCaracteres)
{
	LONGS_EQUAL(strlen("abcdefghi\n"), strlen3("abcdefghi\n"))
}