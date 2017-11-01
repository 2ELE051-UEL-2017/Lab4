#include <string.h>
#include "CppUTest/TestHarness.h"

extern "C" {
	int strcmp2(const char* str1, const char* str2);
}

TEST_GROUP(strcmp2)
{
};

TEST(strcmp2, StringsVazias)
{
	POINTERS_EQUAL(strcmp("", ""), strcmp2("", ""));
}

TEST(strcmp2, StringsUmCaractereIguais)
{
	POINTERS_EQUAL(strcmp("a", "a"), strcmp2("a", "a"));
}

TEST(strcmp2, StringsUmCaractereString1Maior)
{
	POINTERS_EQUAL(strcmp("b", "a"), strcmp2("b", "a"));
}

TEST(strcmp2, StringsUmCaractereString1Menor)
{
	POINTERS_EQUAL(strcmp("a", "b"), strcmp2("a", "b"));
}

TEST(strcmp2, StringsDoisCaracteresIguais)
{
	POINTERS_EQUAL(strcmp("aa", "aa"), strcmp2("aa", "aa"));
}

TEST(strcmp2, StringsDoisCaracteresPrimeiroCaractereString1Maior)
{
	POINTERS_EQUAL(strcmp("ba", "aa"), strcmp2("ba", "aa"));
}

TEST(strcmp2, StringsDoisCaracteresPrimeiroCaractereString1Menor)
{
	POINTERS_EQUAL(strcmp("aa", "ba"), strcmp2("aa", "ba"));
}

TEST(strcmp2, StringsDoisCaracteresSegundoCaractereString1Maior)
{
	POINTERS_EQUAL(strcmp("aa", "ab"), strcmp2("aa", "ab"));
}

TEST(strcmp2, StringsDoisCaracteresSegundoCaractereString1Menor)
{
	POINTERS_EQUAL(strcmp("ab", "aa"), strcmp2("ab", "aa"));
}

TEST(strcmp2, StringsDezCaracteresIguais)
{
	POINTERS_EQUAL(strcmp("abcdefghij", "abcdefghij"), strcmp2("abcdefghij", "abcdefghij"));
}

TEST(strcmp2, StringsDezCaracteresUltimoCaractereString1Maior)
{
	POINTERS_EQUAL(strcmp("abcdefghik", "abcdefghij"), strcmp2("abcdefghik", "abcdefghij"));
}

TEST(strcmp2, StringsDezCaracteresUltimoCaractereString1Menor)
{
	POINTERS_EQUAL(strcmp("abcdefghia", "abcdefghij"), strcmp2("abcdefghia", "abcdefghij"));
}