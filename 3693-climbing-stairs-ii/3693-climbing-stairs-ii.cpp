class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        // dp[j] will store the minimum cost to reach step j
        // We can optimize space by keeping track of the last 3 states.
        // Base cases: dp[0] = 0
        long long dp0 = 0; // represents dp[i-3]
        long long dp1 = 1e18; // represents dp[i-2]
        long long dp2 = 1e18; // represents dp[i-1]
        
        for (int j = 1; j <= n; ++j) {
            long long current_cost = 1e18;
            
            // From j-1 to j
            if (j - 1 >= 0) {
                long long prev_cost = (j - 1 == 0) ? 0 : (j - 1 == 1 ? dp1 : (j - 1 == 2 ? dp2 : 0)); // handle appropriately or store in an array for simplicity
            }
        }
        
        // Using an array of size n + 1 for clarity and safety with constraints:
        vector<long long> dp(n + 1, 1e18);
        dp[0] = 0;
        
        for (int j = 1; j <= n; ++j) {
            for (int i = max(0, j - 3); i < j; ++i) {
                long long jump_cost = costs[j - 1] + 1LL * (j - i) * (j - i);
                dp[j] = min(dp[j], dp[i] + jump_cost);
            }
        }
        
        return dp[n];
    }
};