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
	LONGS_EQUAL(strlen2(""), strlen(""));
}

TEST(strlen2, StringUmCaractere)
{
	LONGS_EQUAL(strlen2("a"), strlen("a"))
}

TEST(strlen2, StringDoisCaracteres)
{
	LONGS_EQUAL(strlen2("ab"), strlen("ab"))
}

TEST(strlen2, StringCincoCaracteres)
{
	LONGS_EQUAL(strlen2("abcd "), strlen("abcd "))
}

TEST(strlen2, StringDezCaracteres)
{
	LONGS_EQUAL(strlen2("abcdefghi\n"), strlen("abcdefghi\n"))
}