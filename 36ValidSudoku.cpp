/* Created on 01 06 2023 - 00:44PM */ 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // feels like theres no way other than just hard coding it ?
        // i mean i can code such that we have 9 sets for each "square"
        // and then determine
        // collection of sets
        vector<set<char>> allsets(9, set<char>());
        // we will update the board with the next location
        // iterate through rows first
        for(int row = 0; row < board.size(); row += 1) {
            set<char> curr_row;
            for (int col = 0; col < board.size(); col += 1) {
                char curr = board[row][col];
                // this is a number
                if (curr = '.') {
                    // checking allsets
                    int allsets_idx = (row / 3) * 3 + col / 3;
                    if (allsets[allsets_idx].count(curr) == 1) { return false; }
                    else { allsets[allsets_idx].insert(curr); }
                    // checking curr row.
                    if (curr_row.count(curr) == 1) { return false; }
                    else { curr_row.insert(curr); }
                }
            }   
        }
        for (int col = 0; col < board.size(); col += 1) {
            set<char> curr_col;
            for(int row = 0; row < board.size(); row += 1) {
                
                char curr = board[row][col];
                // this is a number
                if (curr = '.') {
                    // checking curr row.
                    if (curr_col.count(curr) == 1) { return false; }
                    else { curr_col.insert(curr); }
                }
            }   
        }
        return true;
    }
//[[".",".","4",".",".",".","6","3","."],
// [".",".",".",".",".",".",".",".","."],
// ["5",".",".",".",".",".",".","9","."],
// [".",".",".","5","6",".",".",".","."],
// ["4",".","3",".",".",".",".",".","1"],
// [".",".",".","7",".",".",".",".","."],
// [".",".",".","5",".",".",".",".","."],
// [".",".",".",".",".",".",".",".","."],
// [".",".",".",".",".",".",".",".","."]]
};
