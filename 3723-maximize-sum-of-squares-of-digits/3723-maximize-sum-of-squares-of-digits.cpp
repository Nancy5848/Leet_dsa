class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // Check if the sum is within the valid range
        if (sum < 0 || (long long)num * 9 < sum) {
            return "";
        }
        
        string result = "";
        for (int i = 0; i < num; ++i) {
            // Find the maximum digit we can place at this position
            // We need to ensure the remaining sum can be formed by the remaining positions (num - 1 - i) * 9
            int max_digit = min(9, sum);
            while (max_digit >= 0 && sum - max_digit > (num - 1 - i) * 9) {
                max_digit--;
            }
            
            if (max_digit < 0) {
                return "";
            }
            
            result += to_string(max_digit);
            sum -= max_digit;
        }
        
        return sum == 0 ? result : "";
    }
};