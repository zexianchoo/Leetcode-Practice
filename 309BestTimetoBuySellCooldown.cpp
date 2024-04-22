/* Created on 22 04 2024 - 08:09AM */ 
#define HAVE 0
#define SOLD 1
#define CD 2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        // base cases:
        dp[0][HAVE] = -prices[0];
        dp[0][SOLD] = INT_MIN;
        dp[0][CD] = 0;
        for (int i = 1; i < n; i += 1) {
            dp[i][HAVE] = max(dp[i - 1][HAVE], dp[i - 1][CD] - prices[i]);
            dp[i][SOLD] = dp[i - 1][HAVE] + prices[i];
            dp[i][CD] = max(dp[i - 1][SOLD], dp[i - 1][CD]);
        }
        return max(dp[n - 1][SOLD], dp[n - 1][CD]);
    }
};
