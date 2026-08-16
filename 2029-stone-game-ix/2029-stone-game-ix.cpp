class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};

        // Count stones based on remainder when divided by 3
        for (int x : stones) {
            cnt[x % 3]++;
        }

        int zero = cnt[0];
        int one = cnt[1];
        int two = cnt[2];

        // Case 1: Even number of stones divisible by 3
        if (zero % 2 == 0) {
            return one > 0 && two > 0;
        }

        // Case 2: Odd number of stones divisible by 3
        return abs(one - two) > 2;
    }
};