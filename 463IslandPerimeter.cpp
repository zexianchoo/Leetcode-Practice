/* Created on 26 05 2023 - 09:44PM */ 
class Solution {
public:
    // row, col
    bool boxIsFree(vector<vector<int>>& grid, int row, int col) {
        
        // check out of bounds
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) {
            return true;
        } 
        // check if is another box
        if (grid[row][col] == 1) { return false; }
        return true;
    }
    int countFreeAdj(vector<vector<int>>& grid, int row, int col) {
        return boxIsFree(grid, row + 1, col) + boxIsFree(grid, row - 1, col) + boxIsFree(grid, row, col + 1) + boxIsFree(grid, row, col - 1);   
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        
        // 2 cases when the side cannot be considered to be free:
        // 1. out of bounds
        // 2. facing another land.
        int res = 0;
        for (int row = 0; row < grid.size(); row += 1) {
            for (int col = 0; col < grid[0].size(); col += 1) {
                if (grid[row][col] == 1) res += countFreeAdj(grid, row, col);
            }
        }
        return res;
    }
};
