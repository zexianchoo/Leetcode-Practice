/* Created on 24 06 2023 - 10:06PM */ 
class Solution {
public:
    bool backtrack(vector<vector<char>>& board, vector<vector<bool>>& visited, const string& word, int curr_idx, int row, int col) {
        // found entire word
        if (curr_idx == word.size()) { return true; }
        // out of range check
        if (row >= board.size() || row < 0 || col < 0 || col >= board[0].size()) { return false; }
        // visited check
        if (visited[row][col]) { return false; }
        // found character
        if (word.at(curr_idx) == board[row][col]) {
            visited[row][col] = true;
            // recurse
            bool res = backtrack(board, visited, word, curr_idx + 1, row + 1, col) || backtrack(board, visited, word, curr_idx + 1, row - 1, col) || backtrack(board, visited, word, curr_idx + 1, row, col + 1) || backtrack(board, visited, word, curr_idx + 1, row, col - 1);
            visited[row][col] = false;
            return res;
        }
        else { return false; }
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i += 1) {
            for (int j = 0; j < board[0].size(); j += 1) {
                if(backtrack(board, visited, word, 0, i, j)) { return true;}
            }
        }
        return false;
    }
};
