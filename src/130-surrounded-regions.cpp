class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // a region is surrounded if from any given O there is no path from it to the border of the matrix
        vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> seen;

        for (int i = 0; i < board.size(); ++i) {
            vector<int> row;
            for (int k = 0; k < board[i].size(); ++k) {
                row.push_back(0);
            }
            seen.push_back(row);
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int k = 0; k < board[i].size(); ++k) {
                if (board[i][k] == 'O' && !seen[i][k]) {
                    checkIfSurrounded(board, i, k, seen, directions);
                }
            }
        } 
    }

    void checkIfSurrounded(vector<vector<char>>& board, int x, int y, vector<vector<int>>& seen, vector<pair<int,int>>& directions) {
        queue<pair<int,int>> bfs;
        vector<pair<int,int>> processedCoords;
        processedCoords.push_back({x,y});
        bfs.push({x,y});
        bool regionIsSurrounded = true;

        while (!bfs.empty()) {
            pair<int,int> coord = bfs.front();
            bfs.pop();

            for (int i = 0; i < directions.size(); ++i) {
                int new_x = coord.first + directions[i].first;
                int new_y = coord.second + directions[i].second;

                if (new_x < 0 || new_x >= board.size() || new_y < 0 || new_y >= board[x].size()) {
                    regionIsSurrounded = false;
                    continue;
                }

                if (board[new_x][new_y] == 'X') {
                    continue;
                }

                if (seen[new_x][new_y]) {
                    continue;
                }

                bfs.push({new_x, new_y});
                seen[new_x][new_y] = 1;
                processedCoords.push_back({new_x, new_y});
            }
        }

        if (!regionIsSurrounded) {
            return;
        }

        for (int i = 0; i < processedCoords.size(); ++i) {
            board[processedCoords[i].first][processedCoords[i].second] = 'X';
        }
    }
};
