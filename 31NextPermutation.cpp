/* Created on 29 05 2023 - 09:18PM */ 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        if (nums.size() == 1) { return; }
        // if we are in purely descending order, we must be at the last arrangement
        // to find next permutation, we will look through
        // until we find the first case where it is increasing
        // 5 4 3 1 2 
        int pivot = nums.size() - 2;
        for (; pivot >= 0 && nums[pivot] >= nums[pivot + 1]; pivot--) {}
        // check if we are at the end. if we, we reverse and return
        if (pivot < 0) {
            reverse(nums.begin(), nums.end());
        }
        else { 
            
            //find the largest index greather than k such that nums[k] > nums[l]
            int largest;
            for(largest = nums.size() - 1; largest > pivot && nums[largest] <= nums[pivot]; largest--) {}
            std::swap(nums[pivot], nums[largest]);
            reverse(nums.begin() + pivot + 1, nums.end());
        }
    }
};
