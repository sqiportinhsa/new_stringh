#include <stdlib.h>

int new_puts(const char *str);
const char *new_strchr(const char *str, int sym);
size_t new_strlen(const char *str);
char *new_strcpy(char *str_to, const char *str_from);
char *new_strncpy(char *str_to, const char *str_from, size_t n);
char *new_strcat(char *str_to, const char *str_from);
char *new_strncat(char *str_to, const char *str_from, size_t n);