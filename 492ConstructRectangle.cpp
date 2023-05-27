/* Created on 27 05 2023 - 07:34AM */ 
class Solution {
public:
    vector<int> constructRectangle(int area) {
        
        // i need to search for pairs that work.
        int width = 1, diff = INT_MAX;
        // we will iterate up the width to half way, since it cant be larger than length anyways 
        for (int curr_width = 1; curr_width <= sqrt(area); curr_width += 1) {
            // check if multiple
            int curr_length = area / curr_width;
            // found multiple, store width and diff
            if (curr_width * curr_length == area) {
                if (curr_length - curr_width < diff) {
                    diff = curr_length - curr_width;
                    width = curr_width;
                }
            }
        }
        std::vector<int> res;
        res.push_back(area / width);
        res.push_back(width);
        return res;
    }
};
