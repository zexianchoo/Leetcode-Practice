/* Created on 27 05 2023 - 05:01PM */ 
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        // in pairs of (value, pos)
        std::unordered_map<int, int> num2map; 
        // construct map
        for (int i = 0; i < nums2.size(); i += 1) {
            num2map[nums2[i]] = i;
        }
        vector<int> res;
        for (int i = 0; i < nums1.size(); i += 1) {
            // step 1: find pos in second 
            int currelem = nums1[i];
            int pos = num2map[currelem];
            
            // iterate to end of nums2 and find greater
            int maxelem = currelem;
            for(; pos < nums2.size(); pos += 1) {
                if (nums2[pos] > currelem) {
                    maxelem = nums2[pos];
                    break;
                }
            }
            // no greater found
            if (maxelem == currelem) { maxelem = -1; }
            res.push_back(maxelem);
        }
        return res;
    }
};
