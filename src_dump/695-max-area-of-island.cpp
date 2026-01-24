class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = std::numeric_limits<int>::min();
        vector<vector<int>> seen;
        queue<pair<int,int>> bfs;

        for (int i = 0; i < grid.size(); ++i) {
            vector<int> row;

            for (int k = 0; k < grid[i].size(); ++k) {
                row.push_back(0);
            }

            seen.push_back(row);
        }

        for (int i = 0; i < grid.size(); ++i) {
            for (int k = 0; k < grid[i].size(); ++k) {
                if (grid[i][k] && !seen[i][k]) {
                    int islandSize = discoverIslandSize(grid, seen, i, k);
                    max = std::max(islandSize, max);
                }
            }
        }
        
        if (max == std::numeric_limits<int>::min()) {
            return 0;
        }

        return max;
    }

    int discoverIslandSize(vector<vector<int>>& grid, vector<vector<int>>& seen, int x, int y) {
        queue<pair<int,int>> bfs;
        bfs.push({x,y});

        int counter = 0;

        while (!bfs.empty()) {
            auto index = bfs.front();
            bfs.pop();

            int x = index.first;
            int y = index.second;

            if (seen[x][y]) {
                continue;
            }

            seen[x][y] = 1;
            counter++;

            if (x - 1 >= 0 && grid[x-1][y]) {
                bfs.push({x-1,y});
            }
            
            if (x + 1 < grid.size() && grid[x+1][y]) {
                bfs.push({x+1,y});
            }

            if (y - 1 >= 0 && grid[x][y-1]) {
                bfs.push({x,y-1});
            }

            if (y + 1 < grid[x].size() && grid[x][y+1]) {
                bfs.push({x,y+1});
            }
        }

        return counter;
    }
};
