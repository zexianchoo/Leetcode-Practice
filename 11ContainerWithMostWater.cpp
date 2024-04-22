/* Created on 01 04 2024 - 02:17PM */ 
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        // so we need 2 pointers, and then in between 2 pointers we multiply 
        // by the distance between the pointers
        // idea: keep a "best" left and best right.
        // we will supercede this if we find something better.
        int left = 0;
        int right = height.size() - 1;
        int max_area = min(height[left], height[right]) * right;
        // iterate through, keeping track of best left and best right.
        // if curent improves, supercede.
        while (left < right) {
            //  move the height of the smaller pointer to the center:
            if (height[left] < height[right]) {
                left += 1;
            }
            else {
                right -= 1;
            }
            int length = right - left;
            int curr_area =  min(height[left], height[right]) * length;
            max_area = max(curr_area, max_area);
        }
        return max_area;
    }
};
