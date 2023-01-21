/* finds the largest palindromic substring in a given string */

#include <stdio.h>
#include <string.h>

char * max_pdrome(char *str);
int grow_pdrome(char *str, int ptr1, int ptr2);

int main(void) {
    /* not passing input string 'literally' to
     * max_pdrome as it trunicates the overwriting
     * a character with null which produces segfault
     * as the 'literal' string is read-only */
    char input[] = "dsbba";
    char *pdrome = max_pdrome(input);

    printf("Output: %s\n", pdrome);
    return 0;
}

char * max_pdrome(char *str) {
    int beg, end, slen, len1, len2, len;

    beg = end = 0;
    slen = strlen(str);

    for (int i = 0; i < slen; ++i) {
        len1 = grow_pdrome(str, i, i);
        len2 = grow_pdrome(str, i, i+1);

        if (len1 > len2)
            len = len1;
        else
            len = len2;

        if (len > end - beg) {
            beg = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    str[end+1] = '\0';
    return &str[beg];
}

int grow_pdrome(char *str, int ptr1, int ptr2) {
    int len = strlen(str);
    while (ptr1 >= 0 && ptr2 < len && (str[ptr1] == str[ptr2])) {
        ptr1--;
        ptr2++;
    }
    return ptr2 - ptr1 - 1;
}
