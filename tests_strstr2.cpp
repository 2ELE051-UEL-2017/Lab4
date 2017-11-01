#include <string.h>
#include "CppUTest/TestHarness.h"

extern "C" {
	const char* strstr2(const char* str1, const char* str2);
}

TEST_GROUP(strstr2)
{
};

TEST(strstr2, StringVaziaBuscaUmCaractere)
{
	POINTERS_EQUAL(strstr("", "a"), strstr2("", "a"));
}

TEST(strstr2, StringVaziaBuscaStringVazia)
{
	POINTERS_EQUAL(strstr("", ""), strstr2("", ""));
}

TEST(strstr2, StringUmCaractereBuscaOutroCaractere)
{
	POINTERS_EQUAL(strstr("a", "b"), strstr2("a", "b"));
}

TEST(strstr2, StringUmCaractereBuscaMesmoCaractere)
{
	POINTERS_EQUAL(strstr("a", "a"), strstr2("a", "a"));
}


TEST(strstr2, StringUmCaractereBuscaStringVazia)
{
	POINTERS_EQUAL(strstr("a", ""), strstr2("a", ""));
}

TEST(strstr2, StringUmCaractereBuscaStringDoisCaracteres)
{
	POINTERS_EQUAL(strstr("a", "ab"), strstr2("a", "ab"));
}

TEST(strstr2, StringDoisCaracteresDiferentesBuscaPrimeiroCaractere)
{
	POINTERS_EQUAL(strstr("ab", "a"), strstr2("ab", "a"));
}

TEST(strstr2, StringDoisCaracteresDiferentesBuscaSegundoCaractere)
{
	POINTERS_EQUAL(strstr("ab", "b"), strstr2("ab", "b"));
}

TEST(strstr2, StringDoisCaracteresDiferentesBuscaCaractereInexistente)
{
	POINTERS_EQUAL(strstr("ab", "c"), strstr2("ab", "c"));
}

TEST(strstr2, StringDoisCaracteresDiferentesBuscaDoisCaracteresPrimeiroDiferente)
{
	POINTERS_EQUAL(strstr("ab", "cb"), strstr2("ab", "cb"));
}

TEST(strstr2, StringDoisCaracteresDiferentesBuscaDoisCaracteresSegundoDiferente)
{
	POINTERS_EQUAL(strstr("ab", "ac"), strstr2("ab", "ac"));
}

TEST(strstr2, StringTresCaracteresBuscaDoisCaracteresAlarmeFalso)
{
	POINTERS_EQUAL(strstr("aab", "ab"), strstr2("aab", "ab"));
}

TEST(strstr2, StringSeisCaracteresBuscaTresCaracteresDoisAlarmesFalsos)
{
	POINTERS_EQUAL(strstr("aababc", "abc"), strstr2("aababc", "abc"));
}

TEST(strstr2, StringSeisCaracteresBuscaStringFaltandoUltimoCaractere)
{
	POINTERS_EQUAL(strstr("aababc", "abcd"), strstr2("aababc", "abcd"));
}

TEST(strstr2, StringDezCaracteresBuscaStringCincoCaracteresNoMeio)
{
	POINTERS_EQUAL(strstr("abcdefghij", "defg"), strstr2("abcdefghij", "defg"));
}
