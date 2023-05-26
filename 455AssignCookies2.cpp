/* Created on 26 05 2023 - 06:37PM */ 
class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& sizes) {
        
        // sort cookie sizes
        sort(sizes.begin(), sizes.end());
        sort(greed.begin(), greed.end());
        int greed_idx = 0;
        for (int size_idx = 0; greed_idx < greed.size() && size_idx < sizes.size();) {
            if(sizes[size_idx] >= greed[greed_idx]) {
                greed_idx++;
            }
            size_idx++;
        }
        return greed_idx;
    }
};
