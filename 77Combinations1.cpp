/* Created on 24 06 2023 - 08:14PM */ 
class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int> curr, int curr_idx, int n, int k) {
        if (k <= 0) {
            res.push_back(curr);
            return;
        }
        for (int i = curr_idx; i <= n; i += 1) {
            curr.push_back(i);
            helper(res, curr, i + 1, n, k - 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> res;
        helper(res, vector<int>(), 1, n, k);
        return res;
        
    }
};
