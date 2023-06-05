/* Created on 05 06 2023 - 10:38AM */ 
class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int> candidates, vector<int> ans, vector<bool> visited) {
        
        // base case
        if (ans.size() == candidates.size()) { 
            res.push_back(ans); 
            return; 
        }
        for (int i = 0; i < candidates.size(); i += 1) {
            
            // check if this has not been added. if it hasnt been aded, add it.
            if (visited[i]) {
                visited[i] = true;
                ans.push_back(candidates[i]);
                backtrack(res, candidates, ans, visited);
                ans.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> candidates = nums;
        vector<bool> visited(nums.size(), false);
        // sort
        sort(candidates.begin(), candidates.end());
        // start becktrack
        backtrack(res, candidates, {}, visited);
        return res;
    }
};
// clunky and slow unfortunately
