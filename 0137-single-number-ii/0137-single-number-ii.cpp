class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;

        for (int num : nums) {
            // 'ones' holds bits that appeared once (and not twice or thrice)
            ones = (ones ^ num) & ~twos;
            
            // 'twos' holds bits that appeared twice (and not thrice)
            twos = (twos ^ num) & ~ones;
        }

        return ones;
    }
};