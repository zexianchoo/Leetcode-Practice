/* Created on 01 04 2024 - 05:45PM */ 
class Solution {
public:
    void backtrack(vector<string>& res, string curr, int open, int close) {
        // base case: n == 0 (i.e. we are done) {
        if (open > close || open < 0 || close < 0) { return; }
        if (open == 0 && close == 0) {
            res.push_back(curr);
            return;
        }
        else {
            backtrack(res, curr + "(", open - 1, close);
            backtrack(res, curr + ")", open, close - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        
        // this looks more like backtracking than stack
        vector<string> res;
        backtrack(res, "", n, n);
        return res;
    }
};
