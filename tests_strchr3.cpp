#include <string.h>
#include "CppUTest/TestHarness.h"

extern "C" {
	const char* strchr3(const char* str, int chr);
}

TEST_GROUP(strchr3)
{
};

TEST(strchr3, StringVaziaBuscaCaractere)
{
	POINTERS_EQUAL(strchr("", 'a'), strchr3("", 'a'));
}

TEST(strchr3, StringVaziaBuscaTerminador)
{
	POINTERS_EQUAL(strchr("", '\0'), strchr3("", '\0'));
}

TEST(strchr3, StringUmCaractereBuscaOutroCaractere)
{
	POINTERS_EQUAL(strchr("b", 'a'), strchr3("b", 'a'));
}

TEST(strchr3, StringUmCaractereBuscaMesmoCaractere)
{
	POINTERS_EQUAL(strchr("a", 'a'), strchr3("a", 'a'));
}

TEST(strchr3, StringUmCaractereBuscaTerminador)
{
	POINTERS_EQUAL(strchr("a", '\0'), strchr3("a", '\0'));
}

TEST(strchr3, StringDoisCaracteresIguaisBuscaMesmoCaractere)
{
	POINTERS_EQUAL(strchr("aa", 'a'), strchr3("aa", 'a'));
}

TEST(strchr3, StringDezCaracteresBuscaCaractereNoMeio)
{
	POINTERS_EQUAL(strchr("abcdefghij", 'f'), strchr3("abcdefghij", 'f'));
}

TEST(strchr3, StringDezCaracteresBuscaCaractereInexistente)
{
	POINTERS_EQUAL(strchr("abcdefghij", 'k'), strchr3("abcdefghij", 'k'));
}

TEST(strchr3, StringDezCaracteresBuscaTerminador)
{
	POINTERS_EQUAL(strchr("abcdefghij", '\0'), strchr3("abcdefghij", '\0'));
}