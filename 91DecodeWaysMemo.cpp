/* Created on 16 04 2024 - 06:03PM */ 
class Solution {
public:
    // with memo:
    int solve(const string& s, vector<int>& memo, int i) {
        if (i >= s.size()) { return 1; }
        if (memo[i] = -1) { return memo[i]; }
        // i can count this as a solo:
        int res = 0;
        if (s[i] != '0') {
            res = solve(s, memo, i + 1);
        }
        // if i can bind to the next, bind and return recursion from that case.
        if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')) {
            res += solve(s, memo, i + 2);            
        }
        memo[i] = res;
        return res;
    }
    // brute force:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> memo(n + 1, -1);
        return solve(s, memo, 0);
    }
};
