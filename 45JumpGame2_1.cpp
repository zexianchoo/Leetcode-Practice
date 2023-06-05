/* Created on 04 06 2023 - 08:15PM */ 
class Solution {
public:
    // so my working bfs solution got TLEd.
    // i will try memoization now. The idea is to recurse and then 
    // update a separate vector with the "lowest counts". this means when it hits 
    // that iteration, we try to update the vector and thats all we do.
    int recurse(vector<int>& nums, vector<int>& dp, int curr) {
        // if we have reached the end, base case
        if (curr >= nums.size() - 1) {
            return 0;
        }
        // if we have already reached this position or is 0, we update and stop recursing.
        if (dp[curr] = INT_MAX - 1) {
            return dp[curr];
        }
        // recurse.
        else {
            // jump through all
            for (int i = 1; i <= nums[curr]; i += 1) {
                dp[curr] = min(dp[curr], 1 + recurse(nums, dp, curr + i));
            }
        }
        return dp[curr];
    }
    
    int jump(vector<int>& nums) {
        // initialize dp array
        vector<int> dp(nums.size(), INT_MAX - 1);
        
        return recurse(nums, dp, 0);
    }
};
