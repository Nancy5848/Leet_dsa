class Solution {
public:
    int reverseDegree(string s) {
        long long totalDegree = 0;
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            long long revAlphabetPos = 26 - (s[i] - 'a');
            long long stringPos = i + 1;
            totalDegree += revAlphabetPos * stringPos;
        }
        
        return totalDegree;
    }
};