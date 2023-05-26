/* Created on 26 05 2023 - 02:26PM */ 
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        // hashset
        std::set<int> hashset;
        for (int i : nums) {
            hashset.insert(i);
        }
        // iterate through to figure out which int is missing
        std::vector<int> res;
        for (int i = 1; i <= nums.size(); i += 1) {
            if (hashset.find(i) == hashset.end()) { res.push_back(i); }
        } 
        return res;
    }
};
