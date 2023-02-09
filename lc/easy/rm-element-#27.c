/* Remove all occurrences of a given target in an array. */

#include <stdio.h>

void print_arr(const int *arr, const int size);
int removeElement(int* nums, int numsSize, int val);
int main(void) {
    int size, target, newlen;
    int nums[] = {4, 2, 4, 5, 2, 4, 7, 9, 4};
    size = sizeof(nums)/sizeof(nums[0]);
    target = 4;

    /* Print Input. */
    printf("I: [");
    print_arr(nums, size);
    printf("], %d\n", target);

    newlen = removeElement(nums, size, target);
    /* Print Output. */
    printf("O: [");
    print_arr(nums, size);
    printf("], %d\n", newlen);
    return 0;
}

int removeElement(int* nums, int numsSize, int val){
    int i, j;
    i = 0;
    for (j = 0; j < numsSize; j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}

void print_arr(const int *arr, const int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d", arr[i]);
        if (i != size-1) {
            printf(", ");
        }
    }
}

