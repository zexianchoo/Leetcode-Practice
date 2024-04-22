/* Created on 02 04 2024 - 09:40PM */ 
class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& candidates, vector<int> curr, int idx, int target) {
        if (target == 0) { res.push_back(curr); return; }
        if (target < 0) { return; }
        for (int i = idx; i < candidates.size(); i += 1) {
            curr.push_back(candidates[i]);
            dfs(res, candidates, curr, i, target - candidates[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        dfs(res, candidates, vector<int>(), 0, target);
        return res;
    }
};
