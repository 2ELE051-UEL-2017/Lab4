#include <string.h>
#include "CppUTest/TestHarness.h"

extern "C" {
	int strcmp3(const char* str1, const char* str2);
}

TEST_GROUP(strcmp3)
{
};

TEST(strcmp3, StringsVazias)
{
	POINTERS_EQUAL(strcmp("", ""), strcmp3("", ""));
}

TEST(strcmp3, StringsUmCaractereIguais)
{
	POINTERS_EQUAL(strcmp("a", "a"), strcmp3("a", "a"));
}

TEST(strcmp3, StringsUmCaractereString1Maior)
{
	POINTERS_EQUAL(strcmp("b", "a"), strcmp3("b", "a"));
}

TEST(strcmp3, StringsUmCaractereString1Menor)
{
	POINTERS_EQUAL(strcmp("a", "b"), strcmp3("a", "b"));
}

TEST(strcmp3, StringsDoisCaracteresIguais)
{
	POINTERS_EQUAL(strcmp("aa", "aa"), strcmp3("aa", "aa"));
}

TEST(strcmp3, StringsDoisCaracteresPrimeiroCaractereString1Maior)
{
	POINTERS_EQUAL(strcmp("ba", "aa"), strcmp3("ba", "aa"));
}

TEST(strcmp3, StringsDoisCaracteresPrimeiroCaractereString1Menor)
{
	POINTERS_EQUAL(strcmp("aa", "ba"), strcmp3("aa", "ba"));
}

TEST(strcmp3, StringsDoisCaracteresSegundoCaractereString1Maior)
{
	POINTERS_EQUAL(strcmp("aa", "ab"), strcmp3("aa", "ab"));
}

TEST(strcmp3, StringsDoisCaracteresSegundoCaractereString1Menor)
{
	POINTERS_EQUAL(strcmp("ab", "aa"), strcmp3("ab", "aa"));
}

TEST(strcmp3, StringsDezCaracteresIguais)
{
	POINTERS_EQUAL(strcmp("abcdefghij", "abcdefghij"), strcmp3("abcdefghij", "abcdefghij"));
}

TEST(strcmp3, StringsDezCaracteresUltimoCaractereString1Maior)
{
	POINTERS_EQUAL(strcmp("abcdefghik", "abcdefghij"), strcmp3("abcdefghik", "abcdefghij"));
}

TEST(strcmp3, StringsDezCaracteresUltimoCaractereString1Menor)
{
	POINTERS_EQUAL(strcmp("abcdefghia", "abcdefghij"), strcmp3("abcdefghia", "abcdefghij"));
}