#include <vector>
#include <algorithm>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        // Check if nums is a rotation of the increasing sequence [0, 1, ..., n-1]
        int inc_shift = -1;
        bool is_inc = true;
        for (int i = 0; i < n; ++i) {
            int s = (i - nums[i] + n) % n;
            if (inc_shift == -1) inc_shift = s;
            else if (inc_shift != s) {
                is_inc = false;
                break;
            }
        }

        // Check if nums is a rotation of the decreasing sequence [n-1, n-2, ..., 0]
        // Target value at index i is (n - 1 - i)
        // nums[(i + shift) % n] == n - 1 - i => shift = (nums[i] + i + 1) % n
        int dec_shift = -1;
        bool is_dec = true;
        for (int i = 0; i < n; ++i) {
            int s = (nums[i] + i + 1) % n;
            if (dec_shift == -1) dec_shift = s;
            else if (dec_shift != s) {
                is_dec = false;
                break;
            }
        }

        if (!is_inc && !is_dec) return -1;

        int min_ops = 1e9;

        // If it's a rotation of increasing order:
        if (is_inc) {
            // Option 1: Direct left rotations
            min_ops = std::min(min_ops, inc_shift);
            
            // Option 2: Reverse -> Rotate -> Reverse
            // Reversing changes the type, and the new required shift becomes (n - inc_shift) % n
            int rev_shift = (n - inc_shift) % n;
            min_ops = std::min(min_ops, 1 + rev_shift + 1);
        }

        // If it's a rotation of decreasing order:
        if (is_dec) {
            // Option 1: Reverse first, then rotate by dec_shift
            min_ops = std::min(min_ops, 1 + dec_shift);
            
            // Option 2: Rotate first, then reverse
            int rot_shift = (n - dec_shift) % n;
            min_ops = std::min(min_ops, rot_shift + 1);
        }

        return min_ops;
    }
};