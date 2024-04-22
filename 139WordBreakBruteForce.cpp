/* Created on 18 04 2024 - 07:12PM */ 
class Solution {
public:
    // brute force:
    bool search(const string& s, vector<string>& wordDict, int l, int r) {
        // look at substring from L to R, and then iterate through the word dict.
        // if any of them fit, shift l up and recursively search.
        // Base Case: if any of them have l == r == n then we are return true
        if (l == s.size()) { return true; }
        // base case: if r is already out of the picutre, return false
        if (r >= s.size()) { return false; }
        // if not, we will recursively search
        int window_size = r - l + 1;
        bool res = false; 
        for (auto word : wordDict) {
            
            // found a match
            if (s.compare(l, window_size, word) == 0) {
                res = res || search(s, wordDict, r + 1, r + 1);
            }
        }
        // regularly increment right counter:
        res = res || search(s, wordDict, l, r + 1);
        return res;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return search(s, wordDict, 0, 0);
    }
};
