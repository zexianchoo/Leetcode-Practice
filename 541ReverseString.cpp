/* Created on 30 11 2023 - 11:43PM */ 
class Solution {
public:
    void swapChars (string& s, int l, int r) {
        while(r >= l) {
            std::swap(s[l], s[r]);
            r -= 1;
            l += 1;
        }
    }
    string reverseStr(string s, int k) {
        if (s.size() == 1) { return s; }
        int n = s.size();
        int l = 0;
        int r = 0;
        while(l < s.size()) {
            // try to increment r
            r = min((int)s.size() - 1, l + k - 1);
            
            swapChars(s, l, r);
            l += 2 * k;
        }
        return s;
    }
};
