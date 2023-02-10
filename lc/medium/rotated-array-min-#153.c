/* Find the pivot (minimum element) in a sorted-then-rotated list. In other
 * words, find the 1st element of the unrotated (sorted) array. */

#include <stdio.h>

void print_arr(const int *arr, const int size);
int findMin(int* nums, int numsSize);

int main(void) {
    // int nums[] = {11, 13, 15, 17};
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int size = sizeof(nums)/sizeof(nums[0]);

    printf("I: [");
    print_arr(nums, size);
    printf("]\n");

    printf("O: %d\n", findMin(nums, size));
    return 0;
}

int findMin(int* nums, int numsSize){
    int l, r, m;
    l = 0;
    r = numsSize - 1;

    while (l < r) {
        m = l + (r-l) / 2;

        /* If mid is <= last element then it is an unrotated elements. Also,
         * all elements higher than it cannot be minimum. So, only mid and
         * the elements preceeding it can be the possible minimae. */
        if (nums[m] <= nums[numsSize-1])
            r = m;
        /* If mid > first element, then it is a rotated element. Minima is
         * always the unrotated element and thus lies to its right. */
        else
            l = m + 1;
    }
    return nums[l];
}

void print_arr(const int *arr, const int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d", arr[i]);
        if (i != size-1) {
            printf(", ");
        }
    }
}

