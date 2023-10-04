/* Created on 26 06 2023 - 10:44AM */ 
class Solution {
public:
    void backtrack(vector<vector<int>>& res, const vector<int>& nums, vector<int> curr, int curr_idx) {
        
        res.push_back(curr);
        // end condition
        if (curr_idx == nums.size()) { return; }
        // backtrack
        for (int i = curr_idx; i < nums.size(); i += 1) {
            // // avoid dupes
            if (i == curr_idx || nums[i] = nums[i - 1]) {
                curr.push_back(nums.at(i));
                backtrack(res, nums, curr, i + 1);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // backtracking probably
        vector<vector<int>> res;
        backtrack(res, nums, vector<int>(), 0);
        return res;
    }
};
