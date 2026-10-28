class Solution {
private:
    vector<vector<int>> seen;
    const vector<pair<int,int>> traversableDirections = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };

    int totalIslandsDivisibleByK = 0;

    void initializeSeenGrid(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            std::vector<int> row;
            for (int k = 0; k < grid[i].size(); ++k) {
                row.push_back(0);
            }
            seen.push_back(row);
        }
    }

    void discoverIslandAndDetermineIfDivisibleByK(int x, int y, int k, vector<vector<int>>& grid) {
        std::stack<std::pair<int,int>> dfs;
        dfs.push({x,y});

        long long islandTotalValue = 0;

        while (!dfs.empty()) {
            const auto nextCoordinate = dfs.top();
            dfs.pop();

            if (seen[nextCoordinate.first][nextCoordinate.second]) {
                continue;
            }

            seen[nextCoordinate.first][nextCoordinate.second] = 1;

            islandTotalValue += grid[nextCoordinate.first][nextCoordinate.second];

            for (const auto& dir : traversableDirections) {
                int x_next = nextCoordinate.first + dir.first;
                int y_next = nextCoordinate.second + dir.second;

                if (x_next < 0 || x_next >= seen.size() || y_next < 0 || y_next >= seen[nextCoordinate.first].size()) {
                    continue;
                }

                if (seen[x_next][y_next]) {
                    continue;
                }

                if (grid[x_next][y_next] == 0) {
                    continue;
                }

                dfs.push({x_next, y_next});
            }
        }


        if (islandTotalValue % k == 0) {
            totalIslandsDivisibleByK++;
        }
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        // first part, count all islands and create a list of them
        initializeSeenGrid(grid);

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] > 0 && seen[i][j] != 1) {
                    discoverIslandAndDetermineIfDivisibleByK(i, j, k, grid);
                } 
            }
        }

        return totalIslandsDivisibleByK;
    }
};
