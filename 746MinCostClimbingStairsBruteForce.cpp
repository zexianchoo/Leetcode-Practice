/* Created on 16 04 2024 - 01:08PM */ 
class Solution {
public:
    // brute force recursion:
    int solve(vector<int>& cost, int n) {
        
        // start from 0 or 1.
        if (n < 2) { return 0; }
        int cost_from_two_below = solve(cost, n - 2) + cost[n - 2];
        int cost_from_one_below = solve(cost, n - 1) + cost[n - 1];
        return min(cost_from_two_below, cost_from_one_below);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve(cost, n);
    }
};
