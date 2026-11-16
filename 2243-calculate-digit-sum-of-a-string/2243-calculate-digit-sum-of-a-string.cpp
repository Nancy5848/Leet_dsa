#include <string>
#include <iostream>

class Solution {
public:
    string digitSum(string s, int k) {
        // Repeat the rounds until the string length is no longer greater than k
        while (s.length() > k) {
            string next_round = "";
            
            // Divide s into consecutive groups of size k
            for (size_t i = 0; i < s.length(); i += k) {
                string group = s.substr(i, k);
                
                // Calculate the sum of all digits in the group
                int sum = 0;
                for (char c : group) {
                    sum += (c - '0');
                }
                
                // Append the string representation of the sum to the next round's string
                next_round += std::to_string(sum);
            }
            
            // Update s for the next round
            s = next_round;
        }
        
        return s;
    }
};