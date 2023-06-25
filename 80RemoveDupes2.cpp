/* Created on 25 06 2023 - 09:00AM */ 
class Solution {
public:
        int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (auto e : nums) {
            cout << i << " " << e;
            if (i < 2 || e > nums[i - 2])
                nums[i++] = e;
        }
        return i;
    }
};
