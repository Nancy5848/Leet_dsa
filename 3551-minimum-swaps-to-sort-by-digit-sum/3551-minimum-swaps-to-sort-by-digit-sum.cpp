#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(std::vector<int>& nums) {
        int n = nums.size();
        
        // Store pairs of {number, original_index}
        std::vector<std::pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], i};
        }
        
        // Sort based on digit sum, and value as tie-breaker
        std::sort(arr.begin(), arr.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            int sumA = 0, tempA = a.first;
            while (tempA > 0) { sumA += tempA % 10; tempA /= 10; }
            
            int sumB = 0, tempB = b.first;
            while (tempB > 0) { sumB += tempB % 10; tempB /= 10; }
            
            if (sumA != sumB) return sumA < sumB;
            return a.first < b.first;
        });
        
        // Find minimum swaps using cycle detection
        std::vector<bool> visited(n, false);
        int cycles = 0;
        
        for (int i = 0; i < n; ++i) {
            // If the element is already visited or already in the correct position
            if (visited[i] || arr[i].second == i) {
                continue;
            }
            
            // Traverse the cycle
            int j = i;
            int currentCycleSize = 0;
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                currentCycleSize++;
            }
            
            if (currentCycleSize > 1) {
                cycles += (currentCycleSize - 1);
            }
        }
        
        return cycles;
    }
};