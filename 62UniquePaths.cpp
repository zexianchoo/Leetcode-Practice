/* Created on 09 06 2023 - 02:03PM */ 
class Solution {
public:
    int uniquePaths(int m, int n) {
        // I GOT TLED
        // maybe we try to do a "all ways to reach this box, and all ways to reach end from box is all ways to reach here * all ways to reach end"
        // this feels like a dynamic programming problem.
        // we will traverse the entire row, and then add up the possibilities.
        // initialize vector
        vector<vector<int>> grid(m, vector<int>(n, -1));
        // init first row and first col
        for (int i = 0; i < m; i += 1) {
            grid[i][0] = 1;
        }
        for (int j = 0; j < n; j += 1) {
            grid[0][j] = 1;
        }
        // iterate through rows and add up the res
        for (int i = 1; i < m; i += 1) {
            for (int j = 1; j < n; j += 1) {
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }
        }
        return grid[m - 1][n - 1];
    }
};
