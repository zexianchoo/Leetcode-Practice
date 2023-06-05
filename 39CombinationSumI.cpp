/* Created on 01 06 2023 - 08:24PM */ 
class Solution { 
public: 
 
    void backtrack(vector<int>& candidates, vector<int> curr_comb, int target, int curr_sum, int curr_idx, vector<vector<int>>& answers) { 
 
        // back track if sum is larger than target 
        if (curr_sum > target) { return; } 
 
        // if sum == target, add and back grack/ 
        if (curr_sum == target) { 
            answers.push_back(curr_comb); 
            return; 
        } 
 
        // recurse 
        for(int i = curr_idx; i < candidates.size(); i += 1) { 
            curr_comb.push_back(candidates[i]); 
            curr_sum += candidates[i]; 
            backtrack(candidates, curr_comb, target, curr_sum, i, answers); 
            curr_comb.pop_back(); 
            curr_sum -= candidates[i]; 
        } 
    } 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) { 
        vector<vector<int>> answers; 
        vector<int> curr_comb; 
 
        backtrack(candidates, curr_comb, target, 0, 0, answers); 
        return answers; 
 
    } 
};
