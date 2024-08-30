class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> seen(grid.size(), std::vector<int>(grid[0].size(), 0));  
        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0, 1}};
        int numberOfEnclaves = 0;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int k = 0; k < grid[i].size(); ++k) {
                if (grid[i][k] && !seen[i][k]) {
                    numberOfEnclaves += countEnclaves(seen, grid, i, k, directions);
                }
            }
        }   

        return numberOfEnclaves;
    }

    int countEnclaves(vector<vector<int>>& seen, vector<vector<int>>& grid, int startX, int startY, vector<pair<int,int>>& directions) {
        queue<pair<int,int>> bfs;
        bool touchesEdge = false;
        int pathLength = 1;
        bfs.push({startX, startY});
        seen[startX][startY] = 1;

        while (!bfs.empty()) {
            pair<int,int> cell = bfs.front();
            bfs.pop();
            
            for (const auto& dir : directions) {    
                pair<int,int> newDirection = {cell.first + dir.first, cell.second + dir.second};
                if (newDirection.first >= 0 && newDirection.first < grid.size()
                && newDirection.second >= 0 && newDirection.second < grid[cell.first].size()) 
                {
                    if (grid[newDirection.first][newDirection.second] && !seen[newDirection.first][newDirection.second]) {
                        pathLength++;
                        bfs.push(newDirection);
                        seen[newDirection.first][newDirection.second] = 1;
                    }
                }
                else {
                    touchesEdge = true;
                }
            }
        }

        if (touchesEdge) {
            return 0;
        }

        return pathLength;
    }
};
