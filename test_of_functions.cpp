#include <stdio.h>
#include <string.h>
#include "functions.h"


const char *Functions_tests[] {
    "123", 
    "abc\n",
    "*0123-\n",
    "1a2da"
    ""
};

const int tests_array_size = sizeof(Functions_tests) / sizeof(Functions_tests[0]);

int main() {
    printf("new_puts test started\n");
    printf("it will print all lines from tests");

    for (int ntest = 0; ntest < tests_array_size; ++ntest) {
        if (new_puts(Functions_tests[ntest]) == EOF) {
            printf("new_puts error in test %d", ntest);
        }
    }

    printf("new_puts test completed\n");
    printf("Normal running of following tests is uncompained with output\n");
    printf("new_strchr  test started\n");

    for (int nstring = 0; nstring < tests_array_size; ++nstring) {
        int i = 0;
        do {
            if (new_strchr(Functions_tests[nstring], Functions_tests[nstring][i])
                !=  strchr(Functions_tests[nstring], Functions_tests[nstring][i])) 
            {
                printf("strchr error\n");
                printf("String: <%s>\n", Functions_tests[nstring]);

                printf("The first occurence of element <%c> ", Functions_tests[nstring][i]);

                printf("is position %lld\n", new_strchr(Functions_tests[nstring], 
                    Functions_tests[nstring][i]) - Functions_tests[nstring]);

                printf("Correct position was %lld\n", strchr(Functions_tests[nstring], 
                    Functions_tests[nstring][i]) - Functions_tests[nstring]);
            }
            ++i;
        } while (Functions_tests[nstring][i] != '\0');
    }

    printf("new_strchr  test completed.\n");
    printf("new_strlen  test started\n");

    for (int nstring = 0; nstring < tests_array_size; ++nstring) {
        if (new_strlen(Functions_tests[nstring]) != strlen(Functions_tests[nstring])) {
            printf("new_strlen error\n");
            printf("String: <%s>\n", Functions_tests[nstring]);
            printf("Len: %lld\n", new_strlen(Functions_tests[nstring]));
            printf("Expected len: %lld\n", strlen(Functions_tests[nstring]));
        }
    }

    printf("new_strlen  test completed\n");
    printf("new_strcpy  test started\n");

    for (int ntest = 0; ntest < tests_array_size; ++ntest) {
        size_t size = sizeof(Functions_tests[ntest]);

        char new_strcpy_copy[size] = "";
        char     strcpy_copy[size] = "";

        if (memcmp(new_strcpy(new_strcpy_copy, Functions_tests[ntest]), 
                        strcpy(    strcpy_copy, Functions_tests[ntest]), size)) 
        {
            printf("new_strcpy error\n");
            printf("String:   <%s>\n", new_strcpy_copy);
            printf("Expected: <%s>\n", strcpy_copy);
        }
    }

    printf("new_strcpy  test completed\n");
    printf("new_strncpy test started\n");

    for (int ntest = 0; ntest < tests_array_size; ++ntest) {
        const size_t size = sizeof(Functions_tests[ntest]);

        char new_strncpy_copy_short[size - 1] = "";
        char     strncpy_copy_short[size - 1] = "";

        char new_strncpy_copy_long[size + 2] = "";
        char     strncpy_copy_long[size + 2] = "";

        if (memcmp(new_strncpy(new_strncpy_copy_short, Functions_tests[ntest], size - 1), 
                       strncpy(    strncpy_copy_short, Functions_tests[ntest], size - 1), 
                                                                               size - 1))
        {
            printf("new_strncpy error\n");
            printf("Recieved line:   <%s>\n", new_strncpy_copy_short);
            printf("Expected line:   <%s>\n", strncpy_copy_short);
            printf("Recieved line by chars:");
            for (size_t i = 0; i < size; i++) {
                printf("<%d>", new_strncpy_copy_short[i]);
            }
            printf("\n");
            printf("Expected line by chars:");
            for (size_t i = 0; i < size; i++) {
                printf("<%d>", strncpy_copy_short[i]);
            }
            printf("\n");
        }

        if (memcmp(new_strncpy(new_strncpy_copy_long, Functions_tests[ntest], size + 2), 
                       strncpy(    strncpy_copy_long, Functions_tests[ntest], size + 2), 
                                                                              size + 2))
        {
            printf("new_strcpy error\n");
            printf("Recieved line: <%s>\n", new_strncpy_copy_long);
            printf("Expected line: <%s>\n", strncpy_copy_long);
            printf("Recieved line by chars:");
            for (size_t i = 0; i < size; i++) {
                printf("<%d>", new_strncpy_copy_long[i]);
            }
            printf("\n");
            printf("Expexted line by chars:");
            for (size_t i = 0; i < size; i++) {
                printf("<%d>", strncpy_copy_long[i]);
            }
            printf("\n");
        }
    }

    printf("new_strncpy test completed\n");
    printf("new_strcat  test started\n");

    for (int nstring = 1; nstring < tests_array_size; ++nstring) {
        const size_t size = strlen(Functions_tests[nstring]) + strlen(Functions_tests[nstring - 1]);
        char new_sum_of_lines[size] = {};
        char     sum_of_lines[size] = {};

        new_strcat(new_sum_of_lines, Functions_tests[nstring]);
            strcat(    sum_of_lines, Functions_tests[nstring]);

        new_strcat(new_sum_of_lines, Functions_tests[nstring-1]);
            strcat(    sum_of_lines, Functions_tests[nstring-1]);

        if (memcmp(sum_of_lines, new_sum_of_lines, size)) {
            printf("new_strcat error\n");
            printf("recieved line: <%s>\n", new_sum_of_lines);
            printf("recieved line by chars:");
            int i = 0;
            while (new_sum_of_lines[i] != '\n') {
                printf("<%c>", new_sum_of_lines[i]);
                ++i;
            }
            printf("\nexpexted line: <%s>\n",     sum_of_lines);
        }
    }

    printf("new_strcat  test completed\n");
    printf("new_strncat test started\n");

    for (int nstring = 1; nstring < tests_array_size; ++nstring) {
        const size_t sizen   = sizeof(Functions_tests[nstring]);
        const size_t sizenmo = sizeof(Functions_tests[nstring - 1]);
        const size_t sizesum = sizen + sizenmo;

        char new_strncat_sum_short[sizesum - 1] = "";
        char     strncat_sum_short[sizesum - 1] = "";

        char new_strncat_sum_long[sizesum + 1]  = "";
        char     strncat_sum_long[sizesum + 1]  = "";

        strcpy(new_strncat_sum_long,  Functions_tests[nstring]);
        strcpy(    strncat_sum_long,  Functions_tests[nstring]);
        strcpy(new_strncat_sum_short, Functions_tests[nstring]);
        strcpy(    strncat_sum_short, Functions_tests[nstring]);

        new_strncat(new_strncat_sum_long,  Functions_tests[nstring-1], sizenmo + 1);
            strncat(    strncat_sum_long,  Functions_tests[nstring-1], sizenmo + 1);
        new_strncat(new_strncat_sum_short, Functions_tests[nstring-1], sizenmo - 1);
            strncat(    strncat_sum_short, Functions_tests[nstring-1], sizenmo - 1);

        if (memcmp(new_strncat_sum_short, strncat_sum_short, sizesum - 1))
        {
            printf("new_strncat error\n");
            printf("Recieved line:   <%s>\n", new_strncat_sum_short);
            printf("Expected line:   <%s>\n", strncat_sum_short);
            printf("Recieved line by chars:");
            for (size_t i = 0; i < sizesum - 1; i++) {
                printf("<%d>", new_strncat_sum_short[i]);
            }
            printf("\n");
            printf("Expected line by chars:");
            for (size_t i = 0; i < sizesum - 1; i++) {
                printf("<%d>", strncat_sum_short[i]);
            }
            printf("\n");
        }

        if (memcmp(new_strncat_sum_long, strncat_sum_long, sizesum + 1))
        {
            printf("new_strncat error\n");
            printf("Recieved line: <%s>\n", new_strncat_sum_long);
            printf("Expected line: <%s>\n", strncat_sum_long);
            printf("Recieved line by chars:");
            for (size_t i = 0; i < sizesum + 1; i++) {
                printf("<%d>", new_strncat_sum_long[i]);
            }
            printf("\n");
            printf("Expexted line by chars:");
            for (size_t i = 0; i < sizesum + 1; i++) {
                printf("<%d>", strncat_sum_long[i]);
            }
            printf("\n");
        }
    }

    printf("new_strncat test completed\n");

    return 0;
}
