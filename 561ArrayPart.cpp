/* Created on 01 12 2023 - 05:16PM */ 
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int res = 0;
        for (int i =  0; i < nums.size(); i += 2) {
            res += nums[i];
        }
        return res;
    }
};
