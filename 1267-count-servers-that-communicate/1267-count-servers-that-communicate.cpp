#include <vector>

class Solution {
public:
    int countServers(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        std::vector<int> rowCount(m, 0);
        std::vector<int> colCount(n, 0);
        
        // Step 1: Count the number of servers in each row and column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        // Step 2: Count servers that can communicate
        int communicatingServers = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (rowCount[i] > 1 || colCount[j] > 1) {
                        communicatingServers++;
                    }
                }
            }
        }
        
        return communicatingServers;
    }
};