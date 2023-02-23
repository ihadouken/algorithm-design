/* Reverse a signed 32-bit integer. If the reversal requires more than 32 bits, return 0 */

#include <stdio.h>
#include <limits.h>

int reverse(int x);
int main(void) {
    /*int x = 1534236469; */
    /*int x = 1234;*/
    /*int x = -23443214;*/
    int x = -234120;

    printf("I: %d\n", x);
    printf("O: %d\n", reverse(x));
    return 0;
}

int reverse(int x){
    int digit, res;
    res = 0;

    while (x != 0) {
        digit = x % 10;
        x /= 10;
        if (res > INT_MAX/10 || (res == INT_MAX/10 && digit > INT_MAX%10))
            return 0;
        if (res < INT_MIN/10 || (res == INT_MIN/10 && digit < INT_MIN%10))
            return 0;
        res = res * 10 + digit;
            
    }
    
    return res;
}
