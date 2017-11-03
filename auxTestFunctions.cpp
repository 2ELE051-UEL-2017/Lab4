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

void testMemcmp(const void* ptr1, const void* ptr2, size_t num, int(*myMemcmp)(const void*, const void*, size_t))
{
	int memcmpResult = memcmp(ptr1, ptr2, num);
	int myMemcmpResult = myMemcmp(ptr1, ptr2, num);

	CHECK((memcmpResult == 0 && myMemcmpResult == 0) || (memcmpResult > 0 && myMemcmpResult > 0) || (memcmpResult < 0 && myMemcmpResult < 0));
}

void testMemcpyApenasRetorno(void* ptr1, const void* ptr2, size_t num, void*(*myMemcpy)(void*, const void*, size_t))
{
	POINTERS_EQUAL(ptr1, myMemcpy(ptr1, ptr2, num));
}

void testMemcpyCompleto(void* ptr1, const void* ptr2, size_t num, void*(*myMemcpy)(void*, const void*, size_t))
{
	testMemcpyApenasRetorno(ptr1, ptr2, num, myMemcpy);

	MEMCMP_EQUAL(ptr1, ptr2, num);
}

void testMemsetApenasRetorno(void* ptr, char value, size_t num, void*(*myMemset)(void* ptr, char value, size_t num))
{
	POINTERS_EQUAL(ptr, myMemset(ptr, value, num));
}

void testMemsetCompleto(void* ptr, char value, size_t num, void*(*myMemset)(void* ptr, char value, size_t num))
{
	size_t i;
	char* p = (char*)ptr;

	testMemsetApenasRetorno(ptr, value, num, myMemset);

	for (i = 0; i < num; i++)
		BYTES_EQUAL(value, p[i]);
}
