class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long totalCost = 0;
        
        // 1. Cover the overlapping part of requirements using type 3 or individual items
        long long commonNeed = min(need1, need2);
        totalCost += commonNeed * min((long long)costBoth, (long long)cost1 + cost2);
        
        // 2. Handle remaining requirement for type 1
        if (need1 > commonNeed) {
            long long rem1 = need1 - commonNeed;
            totalCost += rem1 * min((long long)cost1, (long long)costBoth);
        }
        
        // 3. Handle remaining requirement for type 2
        if (need2 > commonNeed) {
            long long rem2 = need2 - commonNeed;
            totalCost += rem2 * min((long long)cost2, (long long)costBoth);
        }
        
        return totalCost;
    }
};