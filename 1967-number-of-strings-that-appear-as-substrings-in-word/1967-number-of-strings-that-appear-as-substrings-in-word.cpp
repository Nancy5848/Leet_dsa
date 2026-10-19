class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (const string& p : patterns) {
            // Check if the pattern exists as a substring in word
            if (word.find(p) != string::npos) {
                count++;
            }
        }
        return count;
    }
};