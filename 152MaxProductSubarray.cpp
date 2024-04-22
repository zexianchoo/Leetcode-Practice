/* Created on 14 04 2024 - 09:03PM */ 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> pos (nums.size() + 1, 0);
        vector<int> neg (nums.size() + 1, 0);
        int highest_positive = nums[0];
        pos[0] = nums[0];
        neg[0] = nums[0];
        for (int i = 1; i < nums.size(); i += 1) {
            
            //  try to fill positive:
            if (nums[i] >= 0) {
                pos[i] = max(nums[i] * pos[i - 1], nums[i]);
                neg[i] = min(nums[i] * neg[i - 1], nums[i]);
            }
            else {
                pos[i] = max(nums[i] * neg[i - 1], nums[i]);
                neg[i] = min(nums[i] * pos[i - 1], nums[i]);      
            }
            highest_positive = max(pos[i], highest_positive);
        }
        return highest_positive;
    }
};
