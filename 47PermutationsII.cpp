/* Created on 05 06 2023 - 11:33AM */ 
class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int> curr, int pos) {
        if (pos >= curr.size()) {
            res.push_back(curr);
            return;
        }
        sort(curr.begin() + pos, curr.end());
        for (int i = pos; i < curr.size(); i += 1) {
            // check if dupe, if it is continue
            if (i > pos && curr[i - 1] == curr[i]) { continue; }
            swap(curr[i], curr[pos]);
            dfs(res, curr, pos + 1);
            swap(curr[i], curr[pos]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> curr = nums;
        // since they want all random, we just start swapping from 0 instead of backtracking.    
        dfs(res, curr, 0);
        return res;
    }
};
