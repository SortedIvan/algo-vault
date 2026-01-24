class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        // we only need to click once
        processClick(click[0], click[1], board);
        return board;
    }

    void processClick(int x, int y, vector<vector<char>>& board) {
        vector<vector<bool>> seen;
        for (int i = 0; i < board.size(); ++i) {
            vector<bool> rowEntry;
            for (int k = 0; k < board[i].size(); ++k) {
                rowEntry.push_back(false);
            }
            seen.push_back(rowEntry);
        }

        if (x < 0 || x >= board.size() || y < 0 || y >= board[x].size()) {
            return;
        }

        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return;
        }

        vector<pair<int,int>> possibleDirections = {
            { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 }, { 1, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }
        };

        queue<pair<int,int>> bfs;
        bfs.push({x,y});
        seen[x][y] = true;

        while (!bfs.empty()) {
            pair<int,int> pos = bfs.front();
            bfs.pop();
            int bombCounter = 0;

            // first, count the number of bombs around a cell
            for (auto dir : possibleDirections) {
                int newPosX = pos.first + dir.first;
                int newPosY = pos.second + dir.second;

                if (newPosX < 0 || newPosX >= board.size() || newPosY < 0 || newPosY >= board[pos.first].size()) {
                    continue;
                }

                if (board[newPosX][newPosY] == 'M') {
                    bombCounter++;
                }
            }

            // if the cell has no bombs around it, we can mark it as E and allow it to potentially reveal its neighbors
            if (bombCounter == 0) {
                board[pos.first][pos.second] = 'B';

                for (auto dir : possibleDirections) {
                    int newPosX = pos.first + dir.first;
                    int newPosY = pos.second + dir.second;

                    if (newPosX < 0 || newPosX >= board.size() || newPosY < 0 || newPosY >= board[pos.first].size()) {
                        continue;
                    }
                    
                    if (seen[newPosX][newPosY]) {
                        continue;
                    }

                    seen[newPosX][newPosY] = true;
                    bfs.push({newPosX, newPosY});
                }
            }
            else {
                char charRepresentation = bombCounter + '0';
                board[pos.first][pos.second] = charRepresentation;
            }
        }
    }
};
