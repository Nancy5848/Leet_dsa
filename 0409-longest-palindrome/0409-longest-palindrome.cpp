class Solution {
public:
    int longestPalindrome(string s) {
        int freq[128] = {0};

        // Count frequency of each character
        for (char ch : s) {
            freq[ch]++;
        }

        int result = 0;
        bool hasOdd = false;

        // Calculate the maximum palindrome length
        for (int i = 0; i < 128; i++) {
            if (freq[i] % 2 == 0) {
                result += freq[i];
            } 
            else {
                result += freq[i] - 1;
                hasOdd = true;
            }
        }

        // One odd character can be placed in the center
        if (hasOdd) {
            result++;
        }

        return result;
    }
};