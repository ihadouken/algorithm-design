/* Find the location of a given element in a sorted numsay using binary search.
 * If the search fails, find an appropriate location for the element if it
 * were to be added to the numsay.*/

#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target);

int main() {
    int len, loc;
    int nums[] = {0, 1, 3, 5, 7, 9, 11};

    len = sizeof(nums) / sizeof(nums[0]);
    loc = searchInsert(nums, len, 8);
    printf("Result: %d\n", loc);
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
