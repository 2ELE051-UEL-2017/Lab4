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
	LONGS_EQUAL(strlen3(""), strlen(""));
}

TEST(strlen3, StringUmCaractere)
{
	LONGS_EQUAL(strlen3("a"), strlen("a"))
}

TEST(strlen3, StringDoisCaracteres)
{
	LONGS_EQUAL(strlen3("ab"), strlen("ab"))
}

TEST(strlen3, StringCincoCaracteres)
{
	LONGS_EQUAL(strlen3("abcd "), strlen("abcd "))
}

TEST(strlen3, StringDezCaracteres)
{
	LONGS_EQUAL(strlen3("abcdefghi\n"), strlen("abcdefghi\n"))
}