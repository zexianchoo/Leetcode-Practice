/* Created on 03 04 2024 - 04:14PM */ 
class Solution {
public:
    void recursiveColour(vector<vector<char>>& grid, int row, int col) {
        // colour if it is suitable
        if(row < grid.size() && row >= 0 && col >= 0 && col < grid[0].size() && grid[row][col] == '1') {
            grid[row][col] = 0;
            recursiveColour(grid, row + 1, col);
            recursiveColour(grid, row - 1, col);
            recursiveColour(grid, row, col - 1);
            recursiveColour(grid, row, col + 1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int colours = 0;
        for (int row = 0; row < grid.size(); row += 1) {
            for (int col = 0; col < grid[0].size(); col += 1) {
                // recursively colour the adjacent if we meet 
                if (grid[row][col] == '1') {
                    recursiveColour(grid, row, col);
                    colours += 1;
                }
            }
        }
        return colours;
    }
};
