/* Created on 02 04 2024 - 11:26AM */ 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") { return 0; }
        if (s.size() == 1) { return 1; }
        int left = 0;
        int right = 1;
        int max_length = 1;
        unordered_map<char, int> counts;
        counts[s[left]] += 1;
        // increment pointers
        while(right < s.size()) {
            cout << s[left] << " " << s[right] << "\n";
            // if it contains, we will increment l until we get a clean string
            while (counts.contains(s[right]) && counts[s[right]] = 0) {
                cout << "inc ";
                counts[s[left]] -= 1;
                left += 1;
                // we the two pointers have met.
                if (left == right) { break; }
            }
            // if it doesnt contain, we will set max length
            max_length = max(max_length, right - left + 1);
            counts[s[right]]++;
            right += 1;
        }        
        return max_length;
    }
};
