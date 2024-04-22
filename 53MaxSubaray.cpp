/* Created on 03 04 2024 - 11:54AM */ 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int best = nums[0];
        int curr_sum = 0;
        for (int i = 0; i < nums.size(); i += 1) {
            curr_sum += nums[i];
            best = max(curr_sum, best);
            if (curr_sum < 0) { curr_sum = 0; }
        }
        return best;
    }
};
