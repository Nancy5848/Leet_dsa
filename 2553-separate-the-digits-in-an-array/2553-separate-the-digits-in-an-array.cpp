#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> separateDigits(std::vector<int>& nums) {
        std::vector<int> answer;
        
        for (int num : nums) {
            std::string str = std::to_string(num);
            for (char c : str) {
                answer.push_back(c - '0');
            }
        }
        
        return answer;
    }
};