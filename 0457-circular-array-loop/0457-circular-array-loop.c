#include <stdbool.h>

int nextIndex(int* nums, int n, int index) {
    return ((index + nums[index]) % n + n) % n;
}

bool circularArrayLoop(int* nums, int numsSize) {
    
    for (int i = 0; i < numsSize; i++) {
        
        // Try only if this index has not been eliminated
        if (nums[i] == 0)
            continue;

        // Direction of the starting index
        bool forward = nums[i] > 0;

        int slow = i;
        int fast = i;

        while (1) {
            
            // Move slow one step
            int nextSlow = nextIndex(nums, numsSize, slow);

            // Check direction
            if ((nums[nextSlow] > 0) != forward)
                break;

            slow = nextSlow;

            // Move fast one step
            int nextFast = nextIndex(nums, numsSize, fast);

            if ((nums[nextFast] > 0) != forward)
                break;

            fast = nextFast;

            // Move fast second step
            nextFast = nextIndex(nums, numsSize, fast);

            if ((nums[nextFast] > 0) != forward)
                break;

            fast = nextFast;

            // Cycle detected
            if (slow == fast) {
                
                // A cycle of length 1 is not allowed
                if (slow == nextIndex(nums, numsSize, slow))
                    break;

                return true;
            }
        }

        // Mark this path as visited
        int current = i;

        while (nums[current] != 0 &&
               ((nums[current] > 0) == forward)) {
            
            int next = nextIndex(nums, numsSize, current);

            // Avoid marking a self-loop as valid
            if (next == current)
                break;

            nums[current] = 0;
            current = next;
        }
    }

    return false;
}