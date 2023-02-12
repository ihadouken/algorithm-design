/* Find the location of a given element in a sorted numsay using binary search.
 * If the search fails, find an appropriate location for the element if it
 * were to be added to the numsay.*/

#include <stdio.h>

void print_arr(const int *arr, const int size);
int searchInsert(int* nums, int numsSize, int target);

int main(void) {
    int size, target;
    int nums[] = {0, 1, 3, 5, 7, 9, 11};
    size = sizeof(nums) / sizeof(nums[0]);
    target = 12;

    /* Print Input. */
    printf("I: [");
    print_arr(nums, size);
    printf("], %d\n", target);

    /* Print Output. */
    printf("O: %d", searchInsert(nums, size, target));
    return 0;
}

int searchInsert(int* nums, int numsSize, int target) {
    int beg, end, mid;
    beg = 0;
    end = numsSize - 1;

    while (beg <= end) {
        mid = (beg + end) / 2;

        if (target == nums[mid])
            return mid;
        else if (target < nums[mid])
            end = mid - 1;
        else
            beg = mid + 1;
    }

    return beg;
}

void print_arr(const int *arr, const int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d", arr[i]);
        if (i != size-1) {
            printf(", ");
        }
    }
}

