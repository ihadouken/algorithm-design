/* Guess a number from 1 to n while getting response higher/lower if the guess
 * is wrong using API function. */

#include <stdio.h>
#define MAXGUESS 100

int guess(int guessed, int ans);
int guessNumber(int n, int ans);

int main(void) {
    int picked = 34;
    printf("I: %d\n", picked);
    printf("O: %d\n", guessNumber(MAXGUESS, picked));
    return 0;
}

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int guessed, int ans) {
    if (guessed > ans)
        return -1;
    else if (guessed < ans)
        return 1;
    else
        return 0;
}

int guessNumber(int n, int ans) {
    int l, m, r;
    l = 1;
    r = n;

    while (l <= r) {
        m = (l+r)/2;
        // printf("Mid: %d\n", m);
        if (guess(m, ans) == -1)
            r = m - 1;
        else if (guess(m, ans) == 1)
            l = m + 1;
        else
            return m;
    }
    return -1;
}

