/* Created on 24 06 2023 - 07:45PM */ 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // follow up: Could you come up with a one-pass algorithm using only constant extra space?
        // triple pointer seems feasible
        int left = 0, mid = 0, right = nums.size() - 1;
        // mid pointer will traverse until it hits high, and disribute 0 and 2s to low and hi
        while (mid <= right) {
            if (nums[mid] == 1) { mid += 1; }
            else if (nums[mid] == 0) {
                
                // swap left and mid 
                swap(nums[left], nums[mid]);
                // increment both tbh
                left++; mid++;
            }
            else if (nums[mid] == 2) {
                
                // swap mid and high
                swap(nums[mid], nums[right]);
                right--;
            } 
        }        
    }
};
