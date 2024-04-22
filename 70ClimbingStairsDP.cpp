/* Created on 16 04 2024 - 01:03PM */ 
class Solution {
public:
    // instead of memoization, deliberately use dp to calc the results
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i += 1) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }
    
};
