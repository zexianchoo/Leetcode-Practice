/* Created on 02 04 2024 - 08:33AM */ 
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        if (nums.size() == 1) { return nums[0]; }
        // we will compare current to elem at [0]. If current > elem[0], we know
        // that "min" elem is to the right
        // else if it is < [0], we know that we are in the "region" or freshly rotated
        // check adjacent for if curr == min, else search left.
        int left = 0; int right = nums.size() - 1;
        int mid;
        while (left < right) {
            if (nums[left] < nums[right]) {
                return nums[left];
            }
            mid = (right + left) / 2;
            
            // min is to right
            if (nums[mid] >= nums[left]) {
                left = mid + 1;
            }
            // else, search left
            else {
                right = mid;
            }
        }
        return nums[left];
        
    }
};
