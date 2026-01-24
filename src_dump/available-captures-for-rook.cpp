class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        std::pair<int,int> rookPosition = std::make_pair(-1,-1);
        int pawnCounter = 0;

        for (int x = 0; x < 8; x++){
            for (int y = 0; y < 8; y++) {
                if (board[x][y] == 'R') {
                    rookPosition = std::make_pair(x,y);
                }
            }
        }

        if (rookPosition.first == -1) {
            return 0;
        }
        
        int pointer = rookPosition.second;
        while (pointer >= 0) {
            if (board[rookPosition.first][pointer] == 'B') {
                break;
            }

            if (board[rookPosition.first][pointer] == 'p') {
                pawnCounter++;
                break;
            }

            pointer--;
        }

        pointer = rookPosition.second;
        while (pointer < 8) {
            if (board[rookPosition.first][pointer] == 'B') {
                break;
            }

            if (board[rookPosition.first][pointer] == 'p') {
                pawnCounter++;
                break;
            }

            pointer++;
        }

        pointer = rookPosition.first;
        while (pointer >= 0) {
            if (board[pointer][rookPosition.second] == 'B') {
                break;
            }

            if (board[pointer][rookPosition.second] == 'p') {
                pawnCounter++;
                break;
            }

            pointer--;
        }

        
        pointer = rookPosition.first;
        while (pointer < 8) {
            if (board[pointer][rookPosition.second] == 'B') {
                break;
            }

            if (board[pointer][rookPosition.second] == 'p') {
                pawnCounter++;
                break;
            }

            pointer++;
        }

        return pawnCounter;
    }
};
