/* Created on 28 05 2023 - 08:03PM */ 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int pos_l = 0, pos_r = height.size() - 1;
        while(pos_r > pos_l) {
            int h = min(height[pos_l], height[pos_r]);
            area = max(area, (pos_r - pos_l) * h);
            while(height[pos_l] <= h && pos_r > pos_l) { pos_l += 1; }
            while(height[pos_r] <= h && pos_r > pos_l) { pos_r -= 1; }         
        }
        return area;
    }
};
