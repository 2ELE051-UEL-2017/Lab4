#include <stddef.h>
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

void testStrncat(const char* expected, char* str1, const char *str2, size_t num, char* (*myStrncat)(char*, const char*, size_t))
{
	POINTERS_EQUAL(str1, myStrncat(str1, str2, num));

	STRCMP_EQUAL(expected, str1);
}