/* Created on 25 05 2023 - 05:31PM */ 
class Solution {
public:
    /*
    1-3: i win
    4: sure lose.
    TLDR, we want to make it such that we can reduce it to 4.
    5-7: sure win
    8: sure lose.
    9: sure win.
    Basically, if we are a multiple of 4, we lose.
    */
    bool canWinNim(int n) {
        return n % 4;
    }
};
