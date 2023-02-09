/* Compute the difference between the product and sum of digits of a number. */

#include <stdio.h>

int subtractProductAndSum(int n);
int main(void) {
    int num = 43562;
    printf("I: %d\n", num);
    printf("O: %d\n", subtractProductAndSum(num));
    return 0;
}

int subtractProductAndSum(int n){
    int sum, product, digit;
    sum = 0;
    product = 1;

    while(n > 0) {
        /* Get the rightmost digit. */
        digit = n % 10;

        /* Add and multiply the digit with sum and product respectively. */
        sum += digit;
        product *= digit;

        /* Shrink the number by one digit from the right. */
        n /= 10;
    }

    return product - sum;
}

