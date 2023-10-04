/* Created on 01 10 2023 - 05:53PM */ 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_map;
        // push 0 onto unordered_map first.
        prefix_map[0] = 1;
        // res is final answer
        int res = 0;
        // curr_sum
        int curr_sum = 0;
        for (int i = 0; i < nums.size(); i += 1) {
            
            // increment curr_sum with the curr value
            curr_sum += nums[i];
            // get number of prefixes that match and add to res
            if (prefix_map.find(curr_sum - k) = prefix_map.end()) {
                res += prefix_map[curr_sum - k];
            }
            // add curr_sum into map.
            prefix_map[curr_sum]++;
        }
        return res;
    }
};
