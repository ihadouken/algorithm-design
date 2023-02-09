/* Remove all multiple occurrences for each element in a sorted array. */

#include <stdio.h>

void print_arr(const int *arr, const int size);
int removeDuplicates(int* nums, int numsSize);
int main(void) {
    int size, newlen;
    int nums[] = {2, 2, 3, 3, 4, 5, 6 , 7, 7};
    size = sizeof(nums)/sizeof(nums[0]);

    /* Print Input. */
    printf("I: [");
    print_arr(nums, size);
    printf("]\n");

    newlen = removeDuplicates(nums, size);
    /* Print Output. */
    printf("O: [");
    print_arr(nums, size);
    printf("], %d\n", newlen);
    return 0;
}

void print_arr(const int *arr, const int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d", arr[i]);
        if (i != size-1) {
            printf(", ");
        }
    }
}

int removeDuplicates(int* nums, int numsSize){
    int i, j;
    i = 0;
    for (j = 1; j < numsSize; j++) {
        if (nums[j] != nums[j-1]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i+1;
}
