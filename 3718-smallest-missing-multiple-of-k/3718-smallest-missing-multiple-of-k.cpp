class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        int multiple = k;
        while (true) {
            if (numSet.find(multiple) == numSet.end()) {
                return multiple;
            }
            multiple += k;
        }
    }
};