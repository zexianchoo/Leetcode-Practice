/* Created on 25 05 2023 - 06:14PM */ 
class Solution {
public:
    int firstUniqChar(string s) {
        
        // i need to preserve index info, as well as count.
        // use hashmap
        std::unordered_map<char, int> char_map;
        std::vector<char> instances;
        // iterate through string
        for (int i = 0; i < s.size(); i += 1) {
            char curr = s.at(i); 
            // update first instance
            instances.push_back(curr);
            // update count
            char_map[curr] += 1;
        }
        // once we have seen all letters, we then check for repeats
        for (int i = 0; i < s.size(); i += 1) {
            // check if it repeats
            if (char_map[instances[i]] == 1) { return i; }
        }
        return -1;
    }
};
