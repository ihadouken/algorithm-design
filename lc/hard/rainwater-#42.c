/* rainwater harvesting problem */

#include <stdio.h>

void print_arr(const int *arr, const int size);
int trap(int *height, int heightSize);

int main(void) {
    /*int height[] = {4, 2, 0, 3, 2, 5};*/
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int size = sizeof(height)/sizeof(height[0]);

    printf("I: ");
    print_arr(height, size);
    putchar('\n');
    printf("O: %d\n", trap(height, size));
    return 0;
}

int trap(int *height, int heightSize) {
    int max_h, stored, temp, beg, i;
    max_h = temp = stored = beg = 0;
    for (i = 0; i < heightSize; ++i) {
        if (height[i] < max_h)
            temp += max_h - height[i];

        else {
            stored += temp;
            temp = 0;
            max_h = height[i];
            beg = i;
        }
    }

    if (i == heightSize && temp != 0) {
        temp = max_h = 0;

        for (i = heightSize - 1; i >= beg; --i) {
            if (height[i] < max_h)
                temp += max_h - height[i];
            else {
                stored += temp;
                temp = 0;
                max_h = height[i];
            }
        }
    }
    return stored;
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

