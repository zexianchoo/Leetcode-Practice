/* Created on 21 04 2024 - 09:16AM */ 
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int total = 0;
        for (int i = 0; i < n; i += 1) {
            total += nums[i];
        }
        if (total % 2 == 1) { return false; }
        int target = total / 2;
        
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i += 1) {
            for (int j = target; j >= 0; j -= 1) {
                if (j - nums[i] >= 0 && dp[j - nums[i]] == true) { dp[j] = true; }
            }
        }
        return dp[target]; 
    }
};
