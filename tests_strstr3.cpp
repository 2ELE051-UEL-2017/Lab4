#include <string.h>
#include "CppUTest/TestHarness.h"

extern "C" {
	const char* strstr3(const char* str1, const char* str2);
}

TEST_GROUP(strstr3)
{
};

TEST(strstr3, StringVaziaBuscaUmCaractere)
{
	POINTERS_EQUAL(strstr("", "a"), strstr3("", "a"));
}

TEST(strstr3, StringVaziaBuscaStringVazia)
{
	POINTERS_EQUAL(strstr("", ""), strstr3("", ""));
}

TEST(strstr3, StringUmCaractereBuscaOutroCaractere)
{
	POINTERS_EQUAL(strstr("a", "b"), strstr3("a", "b"));
}

TEST(strstr3, StringUmCaractereBuscaMesmoCaractere)
{
	POINTERS_EQUAL(strstr("a", "a"), strstr3("a", "a"));
}


TEST(strstr3, StringUmCaractereBuscaStringVazia)
{
	POINTERS_EQUAL(strstr("a", ""), strstr3("a", ""));
}

TEST(strstr3, StringUmCaractereBuscaStringDoisCaracteres)
{
	POINTERS_EQUAL(strstr("a", "ab"), strstr3("a", "ab"));
}

TEST(strstr3, StringDoisCaracteresDiferentesBuscaPrimeiroCaractere)
{
	POINTERS_EQUAL(strstr("ab", "a"), strstr3("ab", "a"));
}

TEST(strstr3, StringDoisCaracteresDiferentesBuscaSegundoCaractere)
{
	POINTERS_EQUAL(strstr("ab", "b"), strstr3("ab", "b"));
}

TEST(strstr3, StringDoisCaracteresDiferentesBuscaCaractereInexistente)
{
	POINTERS_EQUAL(strstr("ab", "c"), strstr3("ab", "c"));
}

TEST(strstr3, StringDoisCaracteresDiferentesBuscaDoisCaracteresPrimeiroDiferente)
{
	POINTERS_EQUAL(strstr("ab", "cb"), strstr3("ab", "cb"));
}

TEST(strstr3, StringDoisCaracteresDiferentesBuscaDoisCaracteresSegundoDiferente)
{
	POINTERS_EQUAL(strstr("ab", "ac"), strstr3("ab", "ac"));
}

TEST(strstr3, StringTresCaracteresBuscaDoisCaracteresAlarmeFalso)
{
	POINTERS_EQUAL(strstr("aab", "ab"), strstr3("aab", "ab"));
}

TEST(strstr3, StringSeisCaracteresBuscaTresCaracteresDoisAlarmesFalsos)
{
	POINTERS_EQUAL(strstr("aababc", "abc"), strstr3("aababc", "abc"));
}

TEST(strstr3, StringSeisCaracteresBuscaStringFaltandoUltimoCaractere)
{
	POINTERS_EQUAL(strstr("aababc", "abcd"), strstr3("aababc", "abcd"));
}

TEST(strstr3, StringDezCaracteresBuscaStringCincoCaracteresNoMeio)
{
	POINTERS_EQUAL(strstr("abcdefghij", "defg"), strstr3("abcdefghij", "defg"));
}
