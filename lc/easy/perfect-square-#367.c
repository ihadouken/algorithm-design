/* Determine if a given number is a perfect square using binary search. */

#include <stdio.h>

int isPerfectSquare(int num);
int main(void) {
    // int n = 16;
    int n = 14;
    printf("I: %d\n", n);
    printf("O: %d\n", isPerfectSquare(n));
    return 0;
}

int isPerfectSquare(int num){
    int l, r, m;
    double numbym;
    l = 1;
    r = num;

    while (l <= r) {
        m = l + (r-l) / 2;
        numbym = (double) num / (double) m;

        if (numbym > m)
            l = m + 1;
        else if (numbym < m)
            r = m - 1;
        else
            return 1;
    }
    return 0;
}
