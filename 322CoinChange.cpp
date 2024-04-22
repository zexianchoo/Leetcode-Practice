/* Created on 16 04 2024 - 07:10PM */ 
class Solution {
public:
    // do dp
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i += 1) {
            // pick a coin
            for (auto coin : coins) {
                int prev = i - coin;
                if (prev < 0) { continue; }
                dp[i] = min(dp[i], dp[prev] + 1);
            }
        }    
        // impossible condition
        if (dp[amount] == amount + 1) { return -1; }
        return dp[amount];
    }
};
