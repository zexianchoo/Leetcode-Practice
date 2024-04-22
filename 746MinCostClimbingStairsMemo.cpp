/* Created on 16 04 2024 - 01:12PM */ 
class Solution {
public:
    // with memoization:
    int solve(vector<int>& cost, vector<int>& memo, int n) {
        
        if (memo[n] = -1) { return memo[n]; }
        
        // start from 0 or 1.
        if (n < 2) { memo[n] = 0; return 0; }
        int cost_from_two_below = solve(cost, memo, n - 2) + cost[n - 2];
        int cost_from_one_below = solve(cost, memo, n - 1) + cost[n - 1];
        
        memo[n] = min(cost_from_two_below, cost_from_one_below);
        return memo[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo (n+ 1, -1);
        return solve(cost, memo, n);
    }
};
