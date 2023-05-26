/* Created on 25 05 2023 - 05:39PM */ 
class Solution {
public:
    int newtonMethod(int n) {
        // start with guess at n/2
        long guess = n;
        // continue guessing
        while (guess*guess > n) {
            guess = (guess + n/guess) / 2;
        }
        return guess;
    }
    bool isPerfectSquare(int num) {
        int res = newtonMethod(num);
        return num == res * res;
    }
};
