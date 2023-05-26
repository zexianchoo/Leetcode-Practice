/* Created on 26 05 2023 - 02:37PM */ 
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    
        vector<bool> seen(nums.size() + 1, false);
        for (int num : nums) {
            seen[num] = true;
        }
        vector<int> res;
        for(int i = 1; i <= nums.size(); i += 1) {
            if (seen[i]) { res.push_back(i); }
        }
        return res;
    }
};
