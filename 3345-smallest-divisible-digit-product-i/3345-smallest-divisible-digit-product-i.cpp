class Solution {
public:
    int smallestNumber(int n, int t) {
        int current = n;
        while (true) {
            // Calculate the digit product of 'current'
            int product = 1;
            int temp = current;
            
            // Handle edge case where number has a 0 digit
            bool hasZero = false;
            while (temp > 0) {
                int digit = temp % 10;
                if (digit == 0) {
                    hasZero = true;
                    break;
                }
                product *= digit;
                temp /= 10;
            }
            
            // If the number contains 0, its product is 0, which is divisible by any t
            if (hasZero || product % t == 0) {
                return current;
            }
            
            current++;
        }
    }
};