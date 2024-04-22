/* Created on 01 04 2024 - 03:13PM */ 
class Solution {
public:
    int trap(vector<int>& height) {
        
        int l = 0; 
        int r = height.size() - 1;
        int max_left = height[l];
        int max_right = height[r];
        int res = 0;
        while (l < r) {
            if (max_left < max_right) {
                
                // shift left pointer
                l += 1;
                // update with max_left
                int add_h = max_left - height[l];
                res += max(add_h, 0);
                max_left = max(height[l], max_left);
            }
            else {
                // shift right pointer
                r -= 1;
                int add_h = max_right - height[r];
                res += max(add_h, 0);
                max_right = max(height[r], max_right);
            }
        }
        return res;
    }
};
