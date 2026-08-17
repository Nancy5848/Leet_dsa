#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * Each array is of size 3.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    
    *returnSize = 0;

    // Maximum possible number of triplets
    int capacity = 1000;

    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    // Sort the array
    int compare(const void* a, const void* b) {
        return (*(int*)a - *(int*)b);
    }

    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize - 2; i++) {

        // Skip duplicate first elements
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        // Since array is sorted, no solution is possible
        if (nums[i] > 0) {
            break;
        }

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {

            long sum = (long)nums[i] + nums[left] + nums[right];

            if (sum == 0) {

                // Increase capacity if necessary
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    result = (int**)realloc(result, capacity * sizeof(int*));
                    *returnColumnSizes = (int*)realloc(
                        *returnColumnSizes,
                        capacity * sizeof(int)
                    );
                }

                // Create triplet
                result[*returnSize] = (int*)malloc(3 * sizeof(int));

                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                // Skip duplicates
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }

                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }

                left++;
                right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return result;
}