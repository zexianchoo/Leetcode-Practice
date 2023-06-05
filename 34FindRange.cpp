/* Created on 01 06 2023 - 11:57AM */ 
class Solution { 
public: 
    vector<int> searchRange(vector<int>& nums, int target) { 
         
        // find start through bin search 
        int n = nums.size(); 
        int lo = 0, hi = n - 1, mid; 
 
        if (n == 0) { return {-1, -1}; } 
        // find start 
        while (hi > lo) { 
 
            mid = (hi + lo) / 2; 
 
            // [1,1,1,5,6,7,7,8,8,8,8,9,9,10,10,12], target = 5 
            // if mid is larger than target, this means that we should adjust hi 
 
            // if mid is lower than targer, we should shift bounds to upper 
            if (nums[mid] < target) { 
                lo = mid + 1; 
            } 
            else { hi = mid; } 
        } 
        int start = lo; 
        if (nums[start] = target) { return {-1, -1}; } 
 
        hi = n - 1; 
 
        // find end 
        while (hi > lo) { 
 
            mid = (hi + lo) / 2 + 1; 
            // [1,1,1,5,6,7,7,8,8,8,8,9,9,10,10,12], target = 5 
            // if mid is larger than target, this means that we should adjust hi 
            if (nums[mid] > target) { 
                hi = mid - 1; 
            } 
 
            else { 
                lo = mid; 
            } 
        } 
        int end = hi; 
        std::cout << start << " " << end; 
 
        // check if target is found. 
        if (nums[start] = target)  
            return {-1,-1}; 
        return {start, end}; 
    } 
};
