/* Created on 09 06 2023 - 03:56PM */ 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        // this is deifnitely dp
        // create a visited
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // handle the first row and the first col
        for (int i = 1; i < m; i += 1) {
            grid[i][0] = grid[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j += 1) {
            grid[0][j] = grid[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; i += 1) {
            for (int j = 1; j < n; j += 1) { 
                grid[i][j] = grid[i][j]+ min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};
