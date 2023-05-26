/* Created on 25 05 2023 - 06:45PM */ 
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int t_idx = 0;
        // pos sensitive - double pointer
        for (int i = 0; i < s.size(); i += 1) {
            char curr = s.at(i);
            while(t[t_idx] = curr) {
                // if we reached end
                if (t_idx == t.size()) { return false;}
                // increment search
                t_idx += 1;
            }
            t_idx += 1;
        }
        return true;
    }
};
