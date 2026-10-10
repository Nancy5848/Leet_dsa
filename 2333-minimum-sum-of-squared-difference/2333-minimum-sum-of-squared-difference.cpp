class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long totalOps = (long long)k1 + k2;
        
        // Find maximum difference to size our frequency array
        int maxDiff = 0;
        vector<long long> count(100005, 0);
        
        for (int i = 0; i < n; ++i) {
            int diff = abs(nums1[i] - nums2[i]);
            count[diff]++;
            maxDiff = max(maxDiff, diff);
        }
        
        // Greedily reduce from the largest differences downwards
        for (int d = maxDiff; d > 0; --d) {
            if (count[d] == 0) continue;
            
            // Number of operations needed to reduce all elements at difference 'd' to 'd - 1'
            long long opsToReduce = min(totalOps, count[d]);
            totalOps -= opsToReduce;
            count[d] -= opsToReduce;
            count[d - 1] += opsToReduce;
            
            if (totalOps == 0) break;
        }
        
        // Calculate the final minimum sum of squared differences
        long long ans = 0;
        for (int d = 0; d <= maxDiff; ++d) {
            if (count[d] > 0) {
                ans += count[d] * (long long)d * d;
            }
        }
        
        return ans;
    }
};