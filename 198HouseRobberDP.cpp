/* Created on 16 04 2024 - 01:37PM */ 
class Solution {
public:
    // deliberate solving
    int rob(vector<int>& nums) {
        if(nums.empty()) { return 0; }
        if (nums.size() == 1) { return nums[0]; }
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        // base cases:
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i += 1) {
            // take one before and not this
            int max_money_from_one_bef = dp[i - 1];
            // take 2 before and this
            int max_money_from_two_bef = dp[i - 2] + nums[i];
            dp[i] = max(max_money_from_one_bef, max_money_from_two_bef);
        }
        return dp[n - 1];
    }
};
