#include <string>
#include <unordered_map>
#include <cmath>

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string result = "";
        
        // Handle signs (XOR determines if the result is negative)
        if ((numerator < 0) ^ (denominator < 0)) {
            result += "-";
        }
        
        // Use long long to avoid integer overflow with INT_MIN
        long long num = std::abs(static_cast<long long>(numerator));
        long long den = std::abs(static_cast<long long>(denominator));
        
        // Integer part
        result += std::to_string(num / den);
        long long remainder = num % den;
        
        if (remainder == 0) {
            return result;
        }
        
        // Fractional part
        result += ".";
        std::unordered_map<long long, int> remainderMap;
        
        while (remainder != 0) {
            // If the remainder has been seen, a repeating cycle is found
            if (remainderMap.find(remainder) != remainderMap.end()) {
                result.insert(remainderMap[remainder], "(");
                result += ")";
                break;
            }
            
            // Record the position of the current remainder
            remainderMap[remainder] = result.length();
            
            remainder *= 10;
            result += std::to_string(remainder / den);
            remainder %= den;
        }
        
        return result;
    }
};