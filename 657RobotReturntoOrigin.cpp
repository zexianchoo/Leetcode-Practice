/* Created on 01 10 2023 - 11:43PM */ 
class Solution {
public:
    bool judgeCircle(string moves) {
        // asset L = r and U = d
        // keep track basically
        // we dont rlly need a hashmap, we just need 4 ints.
        int left = 0, right = 0, up = 0, down = 0;
        for (unsigned int i = 0; i < moves.size(); i += 1) {
            if (moves[i] == 'U') { up += 1; }
            if (moves[i] == 'D') { down += 1;}
            if (moves[i] == 'L') { left += 1; }
            if (moves[i] == 'R') { right += 1;}
        }
        return up == down && left == right;
    } 
};
