#include <string.h>
#include "CppUTest/TestHarness.h"

extern "C" {
	const char* strchr2(const char* str, int chr);
}

TEST_GROUP(strchr2)
{
};

TEST(strchr2, StringVaziaBuscaCaractere)
{
	POINTERS_EQUAL(strchr("", 'a'), strchr2("", 'a'));
}

TEST(strchr2, StringVaziaBuscaTerminador)
{
	POINTERS_EQUAL(strchr("", '\0'), strchr2("", '\0'));
}

TEST(strchr2, StringUmCaractereBuscaOutroCaractere)
{
	POINTERS_EQUAL(strchr("b", 'a'), strchr2("b", 'a'));
}

TEST(strchr2, StringUmCaractereBuscaMesmoCaractere)
{
	POINTERS_EQUAL(strchr("a", 'a'), strchr2("a", 'a'));
}

TEST(strchr2, StringUmCaractereBuscaTerminador)
{
	POINTERS_EQUAL(strchr("a", '\0'), strchr2("a", '\0'));
}

TEST(strchr2, StringDoisCaracteresIguaisBuscaMesmoCaractere)
{
	POINTERS_EQUAL(strchr("aa", 'a'), strchr2("aa", 'a'));
}

TEST(strchr2, StringDezCaracteresBuscaCaractereNoMeio)
{
	POINTERS_EQUAL(strchr("abcdefghij", 'f'), strchr2("abcdefghij", 'f'));
}

TEST(strchr2, StringDezCaracteresBuscaCaractereInexistente)
{
	POINTERS_EQUAL(strchr("abcdefghij", 'k'), strchr2("abcdefghij", 'k'));
}

TEST(strchr2, StringDezCaracteresBuscaTerminador)
{
	POINTERS_EQUAL(strchr("abcdefghij", '\0'), strchr2("abcdefghij", '\0'));
}