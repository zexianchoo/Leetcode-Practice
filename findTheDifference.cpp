/* Created on 25 05 2023 - 06:29PM */ 
class Solution {
public:
    char findTheDifference(string s, string t) {
        
        // obv solution is to use a hashmap, iterate through and remove is count hits 0. 
        std::unordered_map<char, int> counts;
        // get counts
        for (unsigned int i = 0; i < s.size(); i += 1) {
            counts[s.at(i)] += 1;
        }
        // decrement, and remove as we iterate through t.
        for (unsigned int i = 0; i < t.size(); i += 1) {
            --counts[t.at(i)];
            if (counts[t.at(i)] == 0) { counts.erase(t.at(i)); }
        }
        // return char which is remaining
        auto it = counts.begin(); 
        return it->first;
    }
};
