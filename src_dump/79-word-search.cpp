class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        if (word.size() == 0) {
            return true;
        }
        
        if (word.size() == 1) {
            for (int i = 0; i < board.size(); ++i) {
                for (int k = 0; k < board[i].size(); ++k) {
                    if (board[i][k] == word[0]) {
                        return true;
                    }
                }
            }

            return false;
        }

        vector<vector<int>> seen(board.size(), vector<int>(board[0].size(), 0));

        for (int i = 0; i < board.size(); ++i) {
            for (int k = 0; k < board[i].size(); ++k) {
                if (board[i][k] == word[0]) {
                    seen[i][k] = 1;

                    if (existHelper(board, seen, word, 1, i, k)) {
                        return true;
                    }

                    seen[i][k] = 0;
                }
            }
        }

        return false;
    }

    bool existHelper(vector<vector<char>>& board, vector<vector<int>>& seen, string word, int wordPointer, int x, int y) {
        if (wordPointer >= word.size()) {
            return true;
        }

        bool top = false;
        bool bot = false;
        bool left = false;
        bool right = false;

        if (y + 1 < board[x].size() && !seen[x][y+1] && word[wordPointer] == board[x][y+1]) {
            seen[x][y+1] = 1;
            right = existHelper(board, seen, word, wordPointer + 1, x, y+1);
            seen[x][y + 1] = 0;
        }

        if (x + 1 < board.size() && !seen[x+1][y] && word[wordPointer] == board[x+1][y]) {
            seen[x+1][y] = 1;
            bot = existHelper(board, seen, word, wordPointer + 1, x+1, y);
            seen[x+1][y] = 0;
        }

        if (y - 1 >= 0 && !seen[x][y-1] && word[wordPointer] == board[x][y-1]) {
            seen[x][y-1] = 1;
            left = existHelper(board, seen, word, wordPointer + 1, x, y-1);
            seen[x][y-1] = 0;
        }

        if (x - 1 >= 0 && !seen[x-1][y] && word[wordPointer] == board[x-1][y]) {
            seen[x-1][y] = 1;
            top = existHelper(board, seen, word, wordPointer + 1, x-1, y);
            seen[x-1][y] = 0;
        }

        return (top || bot || left || right);
    }
};
