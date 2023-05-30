/* Created on 29 05 2023 - 05:22PM */ 
class Solution {
public:
    void helper(vector<string>& res, string curr, int n, int m) {
        // base case
        if (n == 0 && m == 0) { res.push_back(curr); return; }
        if (n > 0) { helper(res, curr + "(", n - 1, m + 1); }
        if (m > 0) { helper(res, curr + ")", n, m - 1); }
    }
    vector<string> generateParenthesis(int n) {
        // well, whats this problem?
        // i believe it is just P&C, we can solve with recursion easily
        vector<string> res;
        helper(res, "", n, 0);
        return res;
    }
};
