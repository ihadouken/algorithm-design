/* plain old binary search */

#include <stdio.h>

int search(int* nums, int numsSize, int target);
void print_arr(const int *arr, const int size);
int main(void) {
    int size, target;
    int nums[] = {3, 5, 8, 11, 12, 15, 17, 18, 21};
    size = sizeof(nums)/sizeof(nums[0]);
    target = 11;

    /* Print Input. */
    printf("I: ");
    print_arr(nums, size);
    printf(", %d\n", target);

    /* Print Output. */
    printf("O: %d\n", search(nums, size, target));
    return 0;
}

int search(int* nums, int numsSize, int target){
    int l, r, m;
    l = 0;
    r = numsSize - 1;

    while (l <= r) {
        m = (l+r) / 2;
        if (target < nums[m])
            r = m - 1;
        else if (target > nums[m])
            l = m + 1;
        else
            return m;
    }
    return -1;
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

