/* Created on 26 05 2023 - 09:22PM */ 
class Solution {
public:
    string leftShift(string s, int l) {
        string res = s.substr(l);
        res += s.substr(0, l);
        return res;
    }
    bool repeatedSubstringPattern(string s) {
        
        if (s.size() < 1) { return false; }
        // key idea is just to left shift the string, and then compare to original string to see if same.
        for (int i = 1; i < s.size(); i += 1) {
            if (s.size() % i == 0) {
                if (s == leftShift(s, i)) { return true; }
            }
        }
        return false;
    }
};
