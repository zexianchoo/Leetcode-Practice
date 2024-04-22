/* Created on 16 04 2024 - 05:37PM */ 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        if (nums.size() == 1) { return nums[0]; }
        // base case for choose first:
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; i += 1) {
            int choose_two_behind = nums[i] + dp[i - 2];
            int choose_one_behind = dp[i - 1];
            
            dp[i] = max(choose_two_behind, choose_one_behind);
        }
        int choose_first = dp[n - 2];
        // reset base case for choose second:
        dp[0] = 0;
        dp[1] = nums[1];
        for (int i = 2; i < n; i += 1) {
            int choose_two_behind = nums[i] + dp[i - 2];
            int choose_one_behind = dp[i - 1];
            
            dp[i] = max(choose_two_behind, choose_one_behind);
        }
        int choose_second = dp[n - 1];
        return max(choose_first, choose_second);
    }
};
