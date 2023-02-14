/* Find the maximum water that can be contained between any two vertical lines given in an array */

#include <stdio.h>

void print_arr(const int *arr, const int size);
int min(int x, int y);
int max_water(int *height, int heightSize);

int main(void) {
    /*int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};*/
    int height[] = {1, 9, 10, 7, 6, 8, 5};

    int size = sizeof(height)/sizeof(height[0]);

    printf("I: ");
    print_arr(height, size);
    putchar('\n');
    printf("O: %d\n", max_water(height, size));
    return 0;
}

int min(int x, int y) {
    if (x < y)
        return x;
    return y;
}

int max_water(int *height, int heightSize) {
    int l, r, max, water;
    max = 0;
    l = 0;
    r = heightSize - 1;

    while (l < r) {
        water = min(height[l], height[r]) * (r - l);
        if (water > max)
            max = water;

        if (height[l] <= height[r])
            ++l;
        else
            --r;
    }
    return max;
}

void print_arr(const int *arr, const int size) {
    putchar('[');
    for (int i = 0; i < size; ++i) {
        printf("%d", arr[i]);
        if (i != size-1) {
            printf(", ");
        }
    }
    putchar(']');
}

