/* Created on 09 06 2023 - 02:36PM */ 
lass Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        // isnt this the same as literally what we did before?
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // edge case catch obstacle at end or start
        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) { return 0; }
        // as mentioned, initialize with -1 on top and left
        for (int i = 0; i < m; i += 1) {
            // ensure that we break after we meet an obstacle
            if (obstacleGrid[i][0] == 1) { break; }
            else { obstacleGrid[i][0] = -1; }
        }
        for (int j = 0; j < n; j += 1) {
            if (obstacleGrid[0][j] == 1) { break; }
            else { obstacleGrid[0][j] = -1; }
        }
        
        // do the same
        for (int i = 1; i < m; i += 1) {
            for (int j = 1; j < n; j += 1) {
                
                // we met an obstacle
                if (obstacleGrid[i][j] == 1) { continue; }
                int top = obstacleGrid[i - 1][j] == 1 ? 0 : obstacleGrid[i - 1][j];
                int left = obstacleGrid[i][j - 1] == 1 ? 0 : obstacleGrid[i][j - 1];
                // std::cout << i << j << " " << top << " " << left << "\n";
                obstacleGrid[i][j] = top + left;
            }
        }
        return -1 * obstacleGrid[m - 1][n - 1];        
    }
};
