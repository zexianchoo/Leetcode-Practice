/* Created on 03 04 2024 - 06:52PM */ 
class Solution {
public:
    int rob(vector<int>& nums) {
        
        if (nums.size() == 0) { return 0; }
        if (nums.size() < 2) { return nums[0]; }
        
        int n = nums.size() - 1;
        vector<int> dp (n + 1, 0);
        // base cases
        dp[n] = nums[n];
        dp[n - 1] = max(nums[n], nums[n - 1]);
        for (int i = n - 2; i >= 0; i -= 1) {
            
            // pick this + i + 2, else pick i + 1.
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }
        return dp[0];
    }
};
