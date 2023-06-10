/* Created on 05 06 2023 - 04:15PM */ 
class Solution {
public:
    // my first idea would be to sort every string, and then group all
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        // sort all strings and add them to a set.
        vector<string> sorted = strs;
        map<string, vector<int>> groups;
        for (int i = 0; i < sorted.size(); i += 1) {
            sort(sorted[i].begin(), sorted[i].end());
            // if this is a new one, push the index into map
            groups[sorted[i]].push_back(i);
        }
        for (auto it = groups.begin(); it = groups.end(); it++) {
            vector<string> tmp;
            for (int num : it->second) {
                tmp.push_back(strs[num]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
