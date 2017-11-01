#ifndef AUX_TEST_FUNCTIONS_H
#define AUX_TEST_FUNCTIONS_H

#include <stddef.h>

void testStrcpyApenasRetorno(char* dst, const char* src, char* (*myStrcpy)(char*, const char*));
void testStrcpyCompleto(char* dst, const char* src, char* (*myStrcpy)(char*, const char*));
void testStrcat(const char* expected, char* str1, const char *str2, char* (*myStrcat)(char*, const char*));
void testStrncat(const char* expected, char* str1, const char *str2, size_t num, char* (*myStrncat)(char*, const char*, size_t));

#endif // AUX_TEST_FUNCTIONS_H