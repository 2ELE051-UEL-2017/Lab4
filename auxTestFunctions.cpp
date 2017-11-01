#include "CppUTest/TestHarness.h"

void testStrcpyApenasRetorno(char* dst, const char* src, char* (*myStrcpy)(char*, const char*))
{
	POINTERS_EQUAL(dst, myStrcpy(dst, src));
}

void testStrcpyCompleto(char* dst, const char* src, char* (*myStrcpy)(char*, const char*))
{
	testStrcpyApenasRetorno(dst, src, myStrcpy);

	STRCMP_EQUAL(src, dst);
}

void testStrcat(const char* expected, char* str1, const char *str2, char* (*myStrcat)(char*, const char*))
{
	POINTERS_EQUAL(str1, myStrcat(str1, str2));

	STRCMP_EQUAL(expected, str1);
}