/* Created on 26 05 2023 - 06:16PM */ 
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // most obvious thing to do is to sort, and then compare
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        // double pointer and iterate through 
        int res = 0;
        for (int sidx = 0, gidx = 0; sidx < s.size() && gidx < g.size();) {
            // found a cookie that can fit
            if(s[sidx] >= g[gidx]) {
                res += 1;
                gidx++; sidx++;
            }
            // cant find cookie that fits, go to next cookie to fufill this g.
            else {
                sidx++;
            }
        }        
        return res;
    }
};
