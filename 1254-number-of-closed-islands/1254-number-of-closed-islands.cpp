class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Helper function using DFS to traverse and flood fill connected land (0)
        // Returns true if the island is closed (does not touch the boundary), false otherwise.
        auto dfs = [&](auto& self, int r, int c) -> bool {
            // If it goes out of bounds, it touches the border (not closed)
            if (r < 0 || r >= rows || c < 0 || c >= cols) {
                return false;
            }
            // If it's water (1), it's bounded in this direction
            if (grid[r][c] == 1) {
                return true;
            }
            
            // Mark the current cell as visited by turning it into water (1)
            grid[r][c] = 1;
            
            // Explore all 4 directions
            bool left = self(self, r, c - 1);
            bool right = self(self, r, c + 1);
            bool up = self(self, r - 1, c);
            bool down = self(self, r + 1, c);
            
            // An island is closed only if all its parts are completely surrounded by water
            return left && right && up && down;
        };
        
        int closedIslandsCount = 0;
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // Found an unvisited land cell (0)
                if (grid[r][c] == 0) {
                    if (dfs(dfs, r, c)) {
                        closedIslandsCount++;
                    }
                }
            }
        }
        
        return closedIslandsCount;
    }
};