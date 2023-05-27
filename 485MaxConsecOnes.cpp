/* Created on 27 05 2023 - 06:57AM */ 
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // using max function cause we r cheaters
        int res = 0, cnt = 0;
        
        for (int i = 0; i < nums.size(); i += 1) {
            if (nums[i] == 1) {
                cnt += 1;
                res = max(res, cnt);
            }
            else { cnt = 0; }
        }   
        return res;
    }
};
