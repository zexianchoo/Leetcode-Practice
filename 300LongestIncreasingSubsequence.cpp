/* Created on 16 04 2024 - 10:45AM */ 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp (n, 1);
        int ans = 1;
        for (int i = n - 1; i >= 0; i -= 1) {
            for (int j = i; j < n; j += 1) {
                // if the element here can be used, max it out with curerent
                if (nums[j] > nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};
