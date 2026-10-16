#include <vector>
#include <algorithm>

class Solution {
private:
    void backtrack(const std::vector<int>& candidates, int target, int start, 
                   std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // Skip duplicates at the same level of recursion
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            // If the candidate exceeds the remaining target, stop searching
            if (candidates[i] > target) {
                break;
            }

            current.push_back(candidates[i]);
            // Use i + 1 because each number can only be used once
            backtrack(candidates, target - candidates[i], i + 1, current, result);
            current.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        
        // Sort the candidates to handle duplicates and allow early stopping
        std::sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, target, 0, current, result);
        return result;
    }
};