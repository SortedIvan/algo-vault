class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<int>> seen;
        
        for (int i = 0; i < grid1.size(); ++i) {
            vector<int> rowEntry;
            for (int k = 0; k < grid1[i].size(); ++k) {
                rowEntry.push_back(0);
            }
            seen.push_back(rowEntry);
        }

        vector<pair<int,int>> directions = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
        int islandCounter = 0;

        for (int i = 0; i < grid2.size(); ++i) {
            for (int k = 0; k < grid2[i].size(); ++k) {
                if (!seen[i][k] && grid2[i][k]) {
                    if (verifyIsland(grid1, grid2, i,k,seen, directions)) {
                        islandCounter++;
                    }
                }                
            }
        }

        return islandCounter;
    }

    bool verifyIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, 
        int start_x, int start_y, vector<vector<int>>& seen, vector<pair<int,int>>& directions) 
    {
        queue<pair<int,int>> bfs;   
        bfs.push({start_x, start_y});
        seen[start_x][start_y] = 1;
        vector<pair<int,int>> island;
        island.push_back({start_x, start_y});

        while (!bfs.empty()) {
            pair<int,int> top = bfs.front();
            bfs.pop();

            for (const auto& dir : directions) {
                pair<int,int> newDirection = {top.first + dir.first, top.second + dir.second};
                if (newDirection.first >= 0 && newDirection.first < grid1.size() &&
                    newDirection.second >=0 && newDirection.second < grid1[top.first].size()) 
                {
                    if (!seen[newDirection.first][newDirection.second] && grid2[newDirection.first][newDirection.second]) {
                        island.push_back(newDirection);
                        bfs.push(newDirection);
                        seen[newDirection.first][newDirection.second] = 1;
                    }
                }
            }
        }

        if (island.size() == 0) {
            return false;
        } 

        for (const auto& piece : island) {
            if (!grid1[piece.first][piece.second]) {
                return false;
            }
        }

        return true;
    }
};
