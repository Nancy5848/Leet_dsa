class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int k0 = std::bit_ceil((unsigned)n) - 1; // all bits set up to n
        int k = k0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                k &= nums[i];
            }
        }
        
        return (k == k0) ? 0 : k;
    }
};