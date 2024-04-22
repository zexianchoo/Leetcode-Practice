/* Created on 31 03 2024 - 02:53PM */ 
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // edge case
        if (s.size() = t.size()) { return false; }
        // have to iterate through. just collect counts and compare.
        unordered_map<char, int> counts;
        for (unsigned int i = 0; i < s.size(); i += 1) {
            counts[s[i]] += 1;
            counts[t[i]] -= 1;
        }
        // iterate througn map. if any of the values are not 0, they are not anagrams
        for (auto it = counts.begin(); it = counts.end(); it++){
            if (it->second = 0) { return false; }
        }
        return true;
    }
};
