/* Find the peak element i.e element strictly greater than its neighbours) in a given
 * array. In case of multiple peaks, output any one of the peaks. */

#include <stdio.h>

int findPeakElement(int* nums, int numsSize);
void print_arr(const int *arr, const int size);

int main(void) {
    // int nums[] = {1, 2, 3, 1};
    int nums[] = {1,2,1,3,5,6,4};
    int size = sizeof(nums)/sizeof(nums[0]);

    printf("I: ");
    print_arr(nums, size);
    putchar('\n');

    printf("O: %d\n", findPeakElement(nums, size));
    return 0;
}

int findPeakElement(int* nums, int numsSize){
    int l, m, r;
    l = 0;
    r = numsSize - 1;

    /* Template 2 - bsearch */
    // while (l < r) {
    //     m = l + (r-l) / 2;
    //     if (nums[m] > nums[m+1])
    //         r = m;
    //     else
    //         l = m + 1;
    // }
    // return l;

    /* Template 3 - bsearch */
    while (l+1 < r) {
        m = l + (r-l) / 2;
        if (nums[m] > nums[m+1])
            r = m;
        else
            /* The sentinel elements are always greater than imaginary element outside the array. */
            l = m;
    }

    if (nums[r] > nums[l])
        return r;
    /* Left is the peak element when right isn't. For ex: [8, 2]*/
    return l;
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

