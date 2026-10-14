class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;
        // Extract all digits from n
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        
        int max_prod = 0;
        int m = digits.size();
        
        // Find the product of every possible pair of digits
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                // Note: The problem allows using the same digit twice if it appears more than once,
                // which is naturally handled by iterating over all pairs (i, j) including i == j 
                // (or checking distinct indices if you prefer, but standard allows using the same digit twice).
                // Wait, if it appears more than once, indices are different. If it appears once, 
                // can we use the *exact same* physical index twice? 
                // "You may use the same digit twice if it appears more than once in n." -> this means 
                // we can multiply a digit by itself only if there are at least two occurrences. 
                // Let's ensure we only multiply distinct indices.
                if (i != j || (i == j && count(digits.begin(), digits.end(), digits[i]) > 1)) {
                    max_prod = max(max_prod, digits[i] * digits[j]);
                }
            }
        }
        
        return max_prod;
    }
};