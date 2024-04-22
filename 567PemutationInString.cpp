/* Created on 02 04 2024 - 01:48PM */ 
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char, int> counts;
        int left = 0; 
        int right = 0;
        int s1_size = s1.size() - 1;
        // load map with s1:
        for (unsigned int i = 0; i < s1.size(); i += 1) {
            counts[s1[i]] += 1;
        }
        // go through s2:
        for (right = 0; right < s2.size(); right += 1) {
            // increment right:
            counts[s2[right]] -= 1;
            if (counts[s2[right]] == 0) { counts.erase(s2[right]); }
            // if we have to move the window:
            if (right - left > s1_size) {
                counts[s2[left]] += 1;
                if (counts[s2[left]] == 0) { counts.erase(s2[left]); }
                left += 1;
            }
            cout << s2[left] << " " << s2[right] << "\n";
            if (counts.empty()) { return true; }
        }
        return false; 
    }
};
