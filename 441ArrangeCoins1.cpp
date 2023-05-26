/* Created on 26 05 2023 - 01:45PM */ 
class Solution {
public:
    int arrangeCoins(int n) {
        // 1, 2, 3, 4
        // 1, 3, 6, 10
        // n = num/2(2a + (num-1)d)
        // n = a * num + d/2(num(num-1))
        // n = num + 1/2(num^2 - num))
        // n = 1/2 num^2 + 1/2 num
        // solving for math,
        
        return sqrt( long(2)*n + 0.25) - 0.5;
    }
};
