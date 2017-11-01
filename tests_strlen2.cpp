#include <string.h>
#include "CppUTest/TestHarness.h"

extern "C" {
	size_t strlen2(const char* str);
}

TEST_GROUP(strlen2)
{
};

TEST(strlen2, StringVazia)
{
	LONGS_EQUAL(strlen(""), strlen2(""));
}

TEST(strlen2, StringUmCaractere)
{
	LONGS_EQUAL(strlen("a"), strlen2("a"))
}

TEST(strlen2, StringDoisCaracteres)
{
	LONGS_EQUAL(strlen("ab"), strlen2("ab"))
}

TEST(strlen2, StringCincoCaracteres)
{
	LONGS_EQUAL(strlen("abcd "), strlen2("abcd "))
}

TEST(strlen2, StringDezCaracteres)
{
	LONGS_EQUAL(strlen("abcdefghi\n"), strlen2("abcdefghi\n"))
}