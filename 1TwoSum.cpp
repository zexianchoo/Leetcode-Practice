/* Created on 31 03 2024 - 03:15PM */ 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // map numbers. Unfortuantely, we have to also track the indices.
        // first -> first indices, second -> second indices
        unordered_map<int, pair<int, int>> counts;
        // add ints to map
        for (int i = 0; i < nums.size(); i += 1) {
            
            // if present, update second indices
            if (counts.contains(nums[i])) {
                counts[nums[i]].second = i;
            }
            // defaults second to -1 if not present
            else {
                counts[nums[i]] = make_pair(i, -1);
            }
        }
        // iterate through counts, finding required
        for (auto it = counts.begin(); it = counts.end(); it++) {
            int required = target - it->first;
            
            // found
            if (counts.contains(required)) {
                // if we are the edge case of summing both...
                if (it->first == required) {
                    if (counts[required].second == -1) { continue; }
                    vector<int> res = {counts[required].first, counts[required].second};
                    return res;
                }
                else {
                    vector<int> res = {counts[it->first].first, counts[required].first};
                    return res;
                }
            }
        }
        return vector<int>();
    }
};
