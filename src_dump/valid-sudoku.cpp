#include <map>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        std::vector<std::map<char, int>> rows(board.size());
        std::vector<std::map<char, int>> cols(board.size());
        std::vector<std::map<char, int>> boxes(board.size());

        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board.size(); col++) {

                if (board[row][col] == '.') {
                    continue;
                }

                if (rows[row].find(board[row][col]) == rows[row].end()) {
                    rows[row].insert({board[row][col], 1});
                }
                else {
                    return false;
                }

                if (cols[col].find(board[row][col]) == cols[col].end()) {
                    cols[col].insert({board[row][col], 1});
                }
                else {
                    return false;
                }

                // box 1
                if (row >= 0 && row <= 2 && col >=0 && col <= 2) {
                    if (boxes[0].find(board[row][col]) == boxes[0].end()) {
                        boxes[0].insert({board[row][col], 1});
                    }
                    else {
                        return false;
                    }
                }
                // box 2
                if (row >= 0 && row <= 2 && col >=3 && col <= 5) {
                    if (boxes[1].find(board[row][col]) == boxes[1].end()) {
                        boxes[1].insert({board[row][col], 1});
                    }
                    else {
                        return false;
                    }
                }
                // box 3
                if (row >= 0 && row <= 2 && col >=6 && col <= 8) {
                    if (boxes[2].find(board[row][col]) == boxes[2].end()) {
                        boxes[2].insert({board[row][col], 1});
                    }
                    else {
                        return false;
                    }
                }
                // box 4
                if (row >= 3 && row <= 5 && col >=0 && col <= 2) {
                    if (boxes[3].find(board[row][col]) == boxes[3].end()) {
                        boxes[3].insert({board[row][col], 1});
                    }
                    else {
                        return false;
                    }
                }
                // box 5
                if (row >= 3 && row <= 5 && col >=3 && col <= 5) {
                    if (boxes[4].find(board[row][col]) == boxes[4].end()) {
                        boxes[4].insert({board[row][col], 1});
                    }
                    else {
                        return false;
                    }
                }
                // box 6
                if (row >= 3&& row <= 5 && col >=6 && col <= 8) {
                    if (boxes[5].find(board[row][col]) == boxes[5].end()) {
                        boxes[5].insert({board[row][col], 1});
                    }
                    else {
                        return false;
                    }
                }
                // box 7
                if (row >= 6 && row <= 8 && col >=0 && col <= 2) {
                    if (boxes[6].find(board[row][col]) == boxes[6].end()) {
                        boxes[6].insert({board[row][col], 1});
                    }
                    else {
                        return false;
                    }
                }
                // box 8
                if (row >= 6 && row <= 8 && col >=3 && col <= 5) {
                    if (boxes[7].find(board[row][col]) == boxes[7].end()) {
                        boxes[7].insert({board[row][col], 1});
                    }
                    else {
                        return false;
                    }
                }
                // box 9
                if (row >= 6 && row <= 8 && col >=6 && col <= 8) {
                    if (boxes[8].find(board[row][col]) == boxes[8].end()) {
                        boxes[8].insert({board[row][col], 1});
                    }
                    else {
                        return false;
                    }
                }
            }
        } 


        return true;
    }
};
