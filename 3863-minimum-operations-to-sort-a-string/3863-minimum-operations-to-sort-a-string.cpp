#include <string>
#include <algorithm>

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        
        // Check if already sorted
        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end());
        if (s == sorted_s) return 0;
        
        // If length is 2 and not sorted, it's impossible
        if (n == 2) return -1;
        
        char mn = sorted_s[0];
        char mx = sorted_s[n - 1];
        
        // Check if min character is at the beginning or max character is at the end
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }
        
        // Check if min character appears anywhere in proper prefixes or max in proper suffixes
        bool has_mn_in_prefix = false;
        bool has_mx_in_suffix = false;
        
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == mn) has_mn_in_prefix = true;
        }
        for (int i = 1; i < n; ++i) {
            if (s[i] == mx) has_mx_in_suffix = true;
        }
        
        if (!has_mn_in_prefix && !has_mx_in_suffix) {
            return 3;
        }
        
        // Fallback case
        return 2;
    }
};