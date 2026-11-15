class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int oddCount = 0, evenCount = 1; // evenCount = 1 to account for prefix sum 0
        int currentSum = 0;
        long long totalOdds = 0;
        int MOD = 1e9 + 7;

        for (int num : arr) {
            currentSum += num;
            
            if (currentSum % 2 == 1) {
                totalOdds += evenCount;
                oddCount++;
            } else {
                totalOdds += oddCount;
                evenCount++;
            }
        }

        return totalOdds % MOD;
    }
};