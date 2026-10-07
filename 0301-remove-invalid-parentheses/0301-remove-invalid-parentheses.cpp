#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

class Solution {
private:
    // Helper function to check if a parentheses string is valid
    bool isValid(const std::string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) return false; // More closing than opening
            }
        }
        return count == 0;
    }

public:
    std::vector<std::string> removeInvalidParentheses(std::string s) {
        std::vector<std::string> result;
        std::unordered_set<std::string> visited;
        std::queue<std::string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            std::string curr = q.front();
            q.pop();

            if (isValid(curr)) {
                result.push_back(curr);
                found = true; // Mark that we found valid strings at the current level
            }

            // If we've already found a valid string at this level, 
            // don't generate the next level (we only want minimum removals)
            if (found) continue;

            // Generate all possible states by removing one parenthesis
            for (int i = 0; i < curr.length(); i++) {
                if (curr[i] != '(' && curr[i] != ')') continue;

                std::string next_str = curr.substr(0, i) + curr.substr(i + 1);

                if (visited.find(next_str) == visited.end()) {
                    visited.insert(next_str);
                    q.push(next_str);
                }
            }
        }

        return result;
    }
};