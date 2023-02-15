/* Find lowest element in sorted string which is greater than target. If search
 * fails, return first letter in string */

#include <stdio.h>

char nextGreatestLetter(char* letters, int lettersSize, char target);

int main(void) {
    char target;
    int size;

    /*char letters[] = "cfj";*/
    /*target = 'a';*/
    char letters[] = "xxyy";
    target = 'z';
    size = sizeof(letters)/sizeof(letters[0]);

    printf("I: letters = %s, target = %c\n", letters, target);
    printf("O: %c\n", nextGreatestLetter(letters, size, target));
    return 0;
}

char nextGreatestLetter(char* letters, int lettersSize, char target){
    int l, r, m;
    l = 0;
    r = lettersSize - 1;
    
    while (l < r) {
        m = l + (r-l) / 2;
        if (letters[m] > target)
            r = m;
        else
            l = m + 1;
    }
    if (letters[l] > target)
        return letters[l];
    return letters[0];
}

