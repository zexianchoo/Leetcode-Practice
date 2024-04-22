/* Created on 31 03 2024 - 10:20PM */ 
#define BOARD_LENGTH (9)
class Solution {
public:
    bool contains(vector<int>vect, int target) {
        for (int i = 0; i < vect.size(); i += 1) {
            if (vect[i] == target) { return true; }
        }
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (unsigned int row = 0; row < BOARD_LENGTH; row += 1) {
            vector<int> vect;
            for (unsigned int col = 0; col < BOARD_LENGTH; col += 1) {
                if (board[row][col] = '.') {
                    if (contains(vect, board[row][col])) { return false; }
                    vect.push_back(board[row][col] - '\0');
                }
            }
        }
        // check column
        for (unsigned int col = 0; col < BOARD_LENGTH; col += 1) {
            vector<int> vect;
            for (unsigned int row = 0; row < BOARD_LENGTH; row += 1) {
                if (board[row][col] = '.') {
                    if (contains(vect, board[row][col])) { return false; }
                    vect.push_back(board[row][col] - '\0');
                }
            }
        }
        // check square:
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                // check the square:
                vector<int> vect;
                for (int sq_i = i; sq_i < i + 3; sq_i += 1) {
                    for (int sq_j = j; sq_j < j + 3; sq_j += 1) {
                        if (board[sq_i][sq_j] = '.') {
                            if (contains(vect, board[sq_i][sq_j])) { return false; }
                            vect.push_back(board[sq_i][sq_j] - '\0');
                        }
                    }
                }
            }
        }
        return true;
    }
};
