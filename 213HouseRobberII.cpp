/* Created on 14 04 2024 - 03:51PM */ 
class Solution {
public:
    int dpOnSubarray(vector<int>& nums, int start, int end) {
        vector<int> dp(nums.size(), 0);
        // base cases:
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        if (start == 1) {
            dp[0] = 0;
            dp[1] = nums[1];
        }
        for (int i = 2; i < nums.size(); i += 1) {
            // choose between take this and 2 before, or take last.
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
        // edge cases:
        if (nums.size() == 1) { return nums[0]; }
        else if (nums.size() == 2) { return max(nums[0], nums[1]); }
        return max(dpOnSubarray(nums, 0, nums.size() - 2), dpOnSubarray(nums, 1, nums.size() - 1));
    }
};
