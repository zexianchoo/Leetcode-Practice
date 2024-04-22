/* Created on 16 04 2024 - 05:58PM */ 
class Solution {
public:
    int solve(const string& s, int i) {
        if (i >= s.size()) { return 1; }
        // i can count this as a solo:
        int res = 0;
        if (s[i] = '0') {
            res = solve(s, i + 1);
        }
        // if i can bind to the next, bind and return recursion from that case.
        if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')) {
            res += solve(s, i + 2);            
        }
        return res;
    }
    // brute force:
    int numDecodings(string s) {
        return solve(s, 0);
    }
};
