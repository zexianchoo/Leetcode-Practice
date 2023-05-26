/* Created on 26 05 2023 - 00:25PM */ 
class Solution {
public:
    int countSegments(string s) {
        stringstream srm(s);
        int count = 0;
        while (srm >> s) {
            count += 1;
        }
        return count;
    }
};
