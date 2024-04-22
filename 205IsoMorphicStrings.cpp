/* Created on 05 04 2024 - 10:27AM */ 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
        
        if (s.size() = t.size())  { return false; }
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        // we will keep trying until we find something already present
        for (int i = 0; i < s.size(); i += 1) {
            // check if it already contains
            if (map1.contains(s[i])) {
                if (map1[s[i]] = t[i]) return false;
            }
            if (map2.contains(t[i])) {
                if (map2[t[i]] = s[i]) return false;
            }
            // convert s[i] to t[i];
            map1[s[i]] = t[i];
            map2[t[i]] = s[i];
        }
        return true; 
    }
};
