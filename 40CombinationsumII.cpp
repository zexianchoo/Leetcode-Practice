/* Created on 01 06 2023 - 08:24PM */ 
class Solution {
public:
    void backtrack(vector<int> candidates, vector<int> curr_comb, int target, int curr_idx, int curr_sum, vector<vector<int>>& ans) {
        // return if impossible 
        if (curr_sum > target) { return; }
        // add to answer if its equal to target
        if (curr_sum == target) {
            ans.push_back(curr_comb);
            return;
        }
        // backtrack
        for (int i = curr_idx; i < candidates.size(); i += 1) {
            // prevent dupes
            if (i > 0 && candidates[i - 1] == candidates[i] && i > curr_idx) { 
                continue; 
            }
            // create a new curr comb
            curr_comb.push_back(candidates[i]);
            curr_sum += candidates[i];
            backtrack(candidates, curr_comb, target, i + 1, curr_sum, ans);
            curr_sum -= candidates[i];
            curr_comb.pop_back();
        }
    }   
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr_comb;        
        backtrack(candidates, curr_comb, target, 0, 0, ans);
        return ans;
    }
};
