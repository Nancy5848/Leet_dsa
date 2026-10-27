#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> createGrid(int m, int n) {
        // Initialize an m x n grid filled entirely with '#'
        std::vector<std::string> grid(m, std::string(n, '#'));
        
        // Make the entire first row free
        for (int j = 0; j < n; ++j) {
            grid[0][j] = '.';
        }
        
        // Make the entire last column free
        for (int i = 0; i < m; ++i) {
            grid[i][n - 1] = '.';
        }
        
        return grid;
    }
};