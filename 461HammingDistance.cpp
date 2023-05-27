/* Created on 26 05 2023 - 09:26PM */ 
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int p = x ^ y;
        std::cout << p;
        while (p > 0) {
            if (p & 1 == 1) { res += 1; }
            p = p >> 1;
        }
        return res;
    }
};
