/* Created on 16 04 2024 - 01:15PM */ 
class Solution {
public:
    // deliberate calculation of dp:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        // base cases: start at 0 or 1 for free:
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i += 1) {
            // for each level, consider one before and 2 before. Add appropriate cost of taking that step.
            // then, get the min to find the "best solution"
            int two_before_curr = dp[i - 2] + cost[i - 2];
            int one_before_curr = dp[i - 1] + cost[i - 1];
            dp[i] = min(two_before_curr, one_before_curr);
        }
        return dp[n];
    }
};
