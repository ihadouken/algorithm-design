/* Search a rotated but previously sorted array of size n in log(n) time. */

#include <stdio.h>

void print_arr(const int *arr, const int size);
int search(int* nums, int numsSize, int target);
int main(void) {
    int nums[] = {8, 10, 11, 14, 0, 1, 2, 3, 4, 5, 6};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int target = 1;

    /* Print the input (array and target) */
    printf("I: [");
    print_arr(nums, numsSize);
    printf("], %d\n", target);

    /* Print the index of the target or -1 if the search fails. */
    printf("O: %d\n", search(nums, numsSize, target));
    return 0;
}

int search(int* nums, int numsSize, int target){
    int l, r, m;
    l = 0;
    r = numsSize - 1;

    while (l <= r) {
        /* (l+r) / 2 is the same as l + (r-l) / 2 but the intermediate
         * calculation of l+r in the former expression may cause data
         * type overflow in some languages. */
        m = l + (r - l) / 2;
        if (nums[m] == target)
            return m;

        /* Mid in sublist with smaller elements. */
        if (nums[m] < nums[l]) {
            /* target < nums[l] won't work in place of target <= nums[r]
             * if the search space is unrotated. */
            if (nums[m] < target && target <= nums[r])
                l = m + 1;
            else
                r = m - 1;
        }
        else {
            /* target > nums[r] won't work for same above reason. */
            if (nums[m] > target && target >= nums[l])
                r = m - 1;
            else
                l = m + 1;
        }
    }
    return -1;
}


void print_arr(const int *arr, const int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d", arr[i]);
        if (i != size-1)
            printf(", ");
    }
}
