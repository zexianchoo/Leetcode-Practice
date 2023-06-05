/* Created on 05 06 2023 - 11:10AM */ 
class Solution {
public:
    // dfs
    void dfs(vector<vector<int>>& res, vector<int> curr, int pos) {
        // base case: pos is end
        if (pos >= curr.size()) { 
            res.push_back(curr); 
            return; 
        }
        // permute 
        for (int i = pos; i < curr.size(); i += 1) {
            
            // for possibility, swap
            swap(curr[i], curr[pos]);
            dfs(res, curr, pos + 1);
            swap(curr[i], curr[pos]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(res, nums, 0);
        return res;
    }
};
