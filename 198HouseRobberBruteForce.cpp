/* Created on 16 04 2024 - 01:29PM */ 
class Solution {
public:
    // brute force:
    int solve(vector<int>& nums, int curr) {
        // base case
        if (curr < 0) { return 0; }
        // take one before and not this
        int max_money_from_one_bef = solve(nums, curr - 1);
        // take two before and this:
        int max_money_from_two_bef = solve(nums, curr - 2) + nums[curr];
        return max(max_money_from_one_bef, max_money_from_two_bef);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, n - 1);
    }
};
