class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {

        if (grid.size() <= 0) {
            return 0;
        }

        std::vector<std::vector<int>> visited(grid.size(), std::vector<int>(grid[0].size(), 0));
        int numberOfIslands = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int k = 0; k < grid[i].size(); ++k) {
                if (!grid[i][k] && !visited[i][k]) {
                    bool discovered = discoverIsland(grid, visited, i, k);
                    
                    if (discovered) {
                        numberOfIslands++;
                    }
                }
            }
        }

        return numberOfIslands;
    }

    bool isOnEdge(vector<vector<int>>& grid, int x, int y) {
        if (x == 0 || x == grid.size() - 1 || y == 0 || y == grid[0].size() - 1) {
            return true;
        }
        return false;
    }

    bool discoverIsland(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j) {
        queue<pair<int,int>> bfs;
        bfs.push({i, j});
        visited[i][j] = 1; 

        bool correctIsland = true;

        while (!bfs.empty()) {
            auto first = bfs.front();
            bfs.pop();

            int x = first.first;
            int y = first.second;

            if (isOnEdge(grid, x, y)) {
                correctIsland = false;
            }

            if (x - 1 >= 0 && !grid[x-1][y] && !visited[x-1][y]) {
                visited[x-1][y] = 1;
                bfs.push({x-1,y});
            }

            if (x + 1 < grid.size() && !grid[x + 1][y] && !visited[x + 1][y]) {
                visited[x + 1][y] = 1;
                bfs.push({x + 1,y});
            }

            if (y - 1 >= 0 && !grid[x][y - 1] && !visited[x][y - 1]) {
                visited[x][y - 1] = 1;
                bfs.push({x,y - 1});
            }

            if (y + 1 < grid[x].size() && !grid[x][y + 1] && !visited[x][y + 1]) {
                visited[x][y + 1] = 1;
                bfs.push({x,y + 1});
            }

        }

        if (correctIsland) {
            std::cout << i << " " << j << std::endl;
        }

        return correctIsland;
    }
};
