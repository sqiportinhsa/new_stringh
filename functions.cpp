#include "functions.h"

#include <stdio.h>
#include <string.h>

int new_puts(const char *str) {
    int i = 0;
    while (!(str[i] == '\0')) {
        if (putchar(str[i]) == EOF) {
            return EOF;
        }
        ++i;
    }

    if (str[i] != '\n') {
        putchar('\n');
    }

    return 0;
}

const char *new_strchr(const char *str, int sym) {
    int i = 0;
    do {
        if (str[i] == sym) {
            return(str + i);
        }
        ++i;
    } while (!(str[i] == '\0'));

    return 0;
}

size_t new_strlen(const char *str) {
    size_t len = 0;
    for (; str[len] != '\0'; len++);
    return len;
}

char *new_strcpy(char *str_to, const char *str_from) {
    if (str_to == NULL || str_from == NULL) {
        return NULL;
    }

    int i = 0;

    do {
        str_to[i] = str_from[i];
    } while (str_from[i++] != '\0');

    return str_to;
}

char *new_strncpy(char *str_to, const char *str_from, size_t n) {
    if (str_to == NULL || str_from == NULL) {
        return NULL;
    }

    size_t len_of_from = strnlen(str_from, n);

    size_t i = 0;

    if (n > len_of_from) {
        strcpy(str_to, str_from);
        i = len_of_from + 1;

        while (i < n) {
            str_to[i] = '\0';
            ++i;
        }
    }

    while (i < n) {
        str_to[i] = str_from[i];
        ++i;
    }

    return str_to;
}

char *new_strcat(char *str_to, const char *str_from) {
    if (str_to == NULL || str_from == NULL) {
        return NULL;
    }

    size_t len_to = strlen(str_to);

    int i = 0;

    do {
        str_to[len_to + i] = str_from[i];
        ++i;
    } while (str_from[i] != '\0');

    return str_to;
}

char *new_strncat(char *str_to, const char *str_from, size_t n) {
    if (str_to == NULL || str_from == NULL) {
        return NULL;
    }

    size_t len_from = strnlen(str_from, n);
    size_t len_to   = strnlen(str_to,   n);

    size_t i = 0;

    if (n > len_from) {
        strcat(str_to, str_from);
        i = len_from;

        while (i < n) {
            ++i;
            str_to[len_to + i] = '\0';
        }
    }

    while (i < n) {
        str_to[len_to + i] = str_from[i];
        ++i;
   }

    return str_to;
}

char *new_fgets(char *str, int num, FILE *stream) {
    if (str == NULL || stream == NULL) {
        return NULL;
    }

    char c = (char) getc(stream);
    int i = 0;
    while (c != '\n' && c != EOF && i < num) {
        str[i] = c;
        c = (char) getc(stream);
        ++i;
    }

    if (c == '\n') {
        str[i] = '\n';
    }

    str[i + 1] = '\0';
    
    return str;
}

char *new_strdup(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    size_t size = sizeof(str);
    char *dup = (char *) calloc(size, sizeof(char));

    if (dup == NULL) {
        return NULL;
    }

    strcpy(dup, str);

    return dup;
}
