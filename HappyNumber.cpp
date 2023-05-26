/* Created on 25 05 2023 - 05:30PM */ 
class Solution {
public:
/*
 Write an algorithm to determine if a number n is happy.
A happy number is a number defined by the following process:
Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not. 
*/
    int sumDigits(int n) {
        
        int res = 0;
        // loop til n <= 10
        while (n = 0) {
            res += pow(n % 10, 2);
            n /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = sumDigits(slow);
            fast = sumDigits(fast);
            fast = sumDigits(fast);
        }
        while (slow = fast);
        if (slow == 1) { return true; }
        return false;
    }
};
