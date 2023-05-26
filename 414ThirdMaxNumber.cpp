/* Created on 26 05 2023 - 08:27AM */ 
class Solution {
public:
    // maintain max element at vec[0].
    void insertVec(std::vector<int>& vec, int num) {
        
        // insert 5 into 9, 7, 1
        // find index to slot int: 3
        vec.push_back(num);
        for(int idx = 0; idx < 3 && idx < vec.size() ; idx += 1) {
            
            // if greater than current index, replace it, and push the idx back if we are too small
            if (num > vec.at(idx)) {
                std::swap(vec.at(idx), vec.at(vec.size() - 1));
            }
        }
    }
    int thirdMax(vector<int>& nums) {
        // keep track of visited values
        std::set<int> visited_values;
        std::vector<int> top3;
        for (auto num : nums) {
            // if we have no been visited before
            if (visited_values.find(num) == visited_values.end()) {
                insertVec(top3, num);
                visited_values.insert(num);
            }
        }
        // return smallest max
        if (top3.size() < 3) { return top3.at(0); }
        return top3.at(2);
    }
};
