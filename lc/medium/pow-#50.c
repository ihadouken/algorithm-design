/* Compute the power of an rational number x raised to a whole number n. */

#include <stdio.h>
#include <stdlib.h>

double myPow(double x, int n);
int main(void) {
    // double x = 2.00000;
    // int n = 10;
    double x = 2.10000;
    int n = 3;
    // double x = 2.00000;
    // int n = -2;

    printf("I: x = %f, n = %d\n", x, n);
    printf("O: %f\n", myPow(x, n));
    return 0;
}

double myPow(double x, int n) {
    if (x == 0)
        return 0;

    if (n == 0)
        return 1;

    if (n < 0) {
        n = abs(n);
        x = 1/x;
        return myPow(x, n);
    }

    if (n % 2 == 0)
        return myPow(x*x, n/2);
    return x * myPow(x*x, n/2);
}
