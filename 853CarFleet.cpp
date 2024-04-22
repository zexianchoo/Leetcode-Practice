/* Created on 01 04 2024 - 09:34PM */ 
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        // make pairs and push to new array:
        vector<pair<int, float>> cars;
        cars.reserve(sizeof(position));
        for (unsigned int i = 0; i < position.size(); i += 1) {
            // calculate time needed to reach target:
            float time_needed = float(target - position[i]) / speed[i];
            cars.push_back(make_pair(position[i], time_needed));
        }
        // sort array:
        sort(cars.begin(), cars.end());
        // keep stack to track cars:
        stack<float> s;
        for (int i = 0; i < position.size(); i += 1) {
            
            // if this is slower, grab everything until one that is even slower
            while(s.empty() && s.top() <= cars[i].second) {
                s.pop();
            }
            s.push(cars[i].second);
        } 
        return s.size();
    }
};
