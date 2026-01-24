class Solution {
private:
    const int KING_DENOTION = 1;
    const int QUEEN_DENOTION = 2;
    const int CHESSBOARD_SIZE = 8;
    vector<vector<int>> chessBoard;
    
    vector<int> traverseDirectionAndFindQueen(int currX, int currY, const pair<int,int> direction) {
        if (currX >= chessBoard.size() || currX < 0 || currY >= chessBoard.size() || currY < 0) {
            return {-1,-1};
        }        

        if (chessBoard[currX][currY] == QUEEN_DENOTION) {
            return {currX, currY};
        }

        int newX = currX + direction.first;
        int newY = currY + direction.second;

        return traverseDirectionAndFindQueen(newX, newY, direction);
    }

public:
    Solution() {
        for (int i = 0; i < CHESSBOARD_SIZE; ++i) {
            vector<int> row;
            for (int k = 0; k < CHESSBOARD_SIZE; ++k) {
                row.push_back(0);
            }
            chessBoard.push_back(row);
        }
    }

    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        // add the king
        chessBoard[king[0]][king[1]] = KING_DENOTION;

        // add the queens
        for (int i = 0; i < queens.size(); ++i) {
            chessBoard[queens[i][0]][queens[i][1]] = QUEEN_DENOTION;
        }

        vector<pair<int,int>> directions = {
            {1,0}, {0,1}, {1,1}, {-1,0}, {0, -1}, {-1, -1}, {-1, 1}, {1,-1}
        };

        std::vector<vector<int>> queensThatCanAttack;

        for (const auto& direction : directions) {
            auto result = traverseDirectionAndFindQueen(king[0], king[1], direction);
            if (result[0] != -1) {
                queensThatCanAttack.push_back(result);
            }
        }

        return queensThatCanAttack;
    }



};          
