/* Created on 24 06 2023 - 08:48PM */ 
class Solution {
public:
    void helper(vector<vector<int>>& res, const vector<int>& nums, vector<int> curr, int curr_idx) {
        
        res.push_back(curr);
        // base case where we are at end
        if (curr_idx >= nums.size()) { return; }
        for (int i = curr_idx; i < nums.size(); i += 1) {
            curr.push_back(nums[i]);
            helper(res, nums, curr, i + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        helper(res, nums, vector<int>(), 0);
        return res;
    }
};
