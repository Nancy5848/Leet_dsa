class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minVal = nums[0];
        int maxVal = nums[0];
        
        for (int num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }
        
        return std::gcd(minVal, maxVal);
    }
};