/* Created on 03 04 2024 - 04:52PM */ 
class Solution {
public:
    int countArea(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0) {
            return 0;
        }
        grid[row][col] = 0;
        return 1 + countArea(grid, row + 1, col) + \
                countArea(grid, row - 1, col) + \
                countArea(grid, row, col - 1) + \
                countArea(grid, row, col + 1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int row = 0; row < grid.size(); row += 1) {
            for (int col = 0; col < grid[0].size(); col += 1) {
                res = max(res, countArea(grid, row, col));
            }
        }
        
        return res;
    }
};
