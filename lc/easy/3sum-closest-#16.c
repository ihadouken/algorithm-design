/* finds a triplet whose sum is closest to a given target number in the given array */

#include <stdio.h>
#include <stdlib.h>

void print_arr(const int *arr, const int size);
int closest_triplet_sum(int* arr, int len, int target);
int closest_duet_sum(int* arr, int len, int target);
unsigned int abs_val(int val);
int cmpfunc (const void * a, const void * b);

int main(void) {
    int size, target;
    // int nums[] = {5, 12, -9, 43, 2, -65, 3, 4, 19, 23, -11};
    int nums[] = {2, 100, 150, 8, 10, 200};
    size = sizeof(nums)/sizeof(nums[0]);
    target = 214;

    printf("I: ");
    print_arr(nums, size);
    printf(", %d\n", target);
    printf("O: %d\n", closest_triplet_sum(nums, size, 214));
    return 0;
}

int closest_triplet_sum(int* arr, int len, int target) {
    int closest, sum, p1, p2, two_sum;
    closest = arr[0] + arr[1] + arr[2];

    qsort(arr, len, sizeof(int), cmpfunc);

    for (int i = 0; i < len - 2; ++i) {
        p1 = i + 1;
        p2 = len - 1;

        while (p1 < p2) {
            two_sum = arr[p1] + arr[p2];
            sum = two_sum + arr[i];

            if (two_sum == target - arr[i])
                return sum;
            else if (two_sum > target - arr[i])
                p2--;
            else
                p1++;

            if (abs_val(target-sum) < abs_val(target-closest))
                closest = sum;
        }
    }
    return closest;
}

unsigned int abs_val(int val) {
    if (val < 0)
        return val * -1;
    else
        return val;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
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

