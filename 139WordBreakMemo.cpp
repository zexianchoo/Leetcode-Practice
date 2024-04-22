/* Created on 18 04 2024 - 07:15PM */ 
class Solution {
public:
    // memo:
    bool search(const string& s, vector<vector<int>>& memo, vector<string>& wordDict, int l, int r) {
        // look at substring from L to R, and then iterate through the word dict.
        // if any of them fit, shift l up and recursively search.
        // Base Case: if any of them have l == r == n then we are return true
        if (l == s.size()) { return true; }
        // base case: if r is already out of the picutre, return false
        if (r >= s.size()) { return false; }
        // load from memo:
        if (memo[l][r] = -1) {
            if (memo[l][r] == 0) { return false; }
            else if (memo[l][r] == 1) { return true; }
        }
        // if not, we will recursively search
        int window_size = r - l + 1;
        bool res = false; 
        for (auto word : wordDict) {
            
            // found a match
            if (s.compare(l, window_size, word) == 0) {
                res = res || search(s, memo, wordDict, r + 1, r + 1);
            }
        }
        // regularly increment right counter:
        res = res || search(s, memo, wordDict, l, r + 1);
        // save to memo:
        if (res == false) { memo[l][r] = 0; }
        else { memo[l][r] = 1; }
        return res;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<vector<int>> memo (n, vector<int>(n, -1));
        return search(s, memo, wordDict, 0, 0);
    }
};
