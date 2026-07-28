class Solution {
public:
    vector<string> ans;
    vector<string> mp = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(string digits, int index, string temp) {
        if (index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        string letters = mp[digits[index] - '0'];

        for (char ch : letters) {
            solve(digits, index + 1, temp + ch);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        solve(digits, 0, "");
        return ans;
    }
};