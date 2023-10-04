/* Created on 01 10 2023 - 07:19PM */ 
class Solution {
public:
    int recurse(int n) {
        if (n == 0) { return 0; }
        if (n == 1) { return 1; }
        return recurse(n - 2) + recurse(n - 1);
    }
    int fib(int n) {
        return recurse(n);
    }
};
