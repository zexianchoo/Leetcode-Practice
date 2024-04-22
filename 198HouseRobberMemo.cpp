/* Created on 16 04 2024 - 01:31PM */ 
class Solution {
public:
    // brute force:
    int solve(vector<int>& nums, vector<int>& memo, int curr) {
        // base case
        if (curr < 0) { return 0; }
        if (memo[curr] = -1) { return memo[curr]; }
        // take one before and not this
        int max_money_from_one_bef = solve(nums, memo, curr - 1);
        // take two before and this:
        int max_money_from_two_bef = solve(nums, memo, curr - 2) + nums[curr];
        memo[curr] = max(max_money_from_one_bef, max_money_from_two_bef);
        return memo[curr];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n + 1, -1);
        return solve(nums, memo, n - 1);
    }
};
