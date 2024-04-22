/* Created on 31 03 2024 - 03:58PM */ 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // use sorted anagram as key.
        unordered_map<string, int> indices;
        vector<vector<string>> res;
        // for each str in strs, sort them and check if we have them added. 
        // if not added, push to res a new vector
        // otherwise, add to the res.
        for (int i = 0; i < strs.size(); i += 1) {
            string to_place = strs[i];
            string sorted_anag = to_place;
            sort(sorted_anag.begin(), sorted_anag.end());
            
            // if this is in a group, place this into the group
            if(indices.contains(sorted_anag)){
                int idx = indices[sorted_anag];
                res[idx].push_back(to_place);
            }
            // else, make new group, push to indices
            else {
                vector<string> to_add = {to_place};
                res.push_back(to_add);
                indices[sorted_anag] = res.size() - 1;
            }
        }
        return res;
    }
};
