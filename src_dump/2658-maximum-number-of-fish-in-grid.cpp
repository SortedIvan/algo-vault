class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        vector<pair<int,int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<std::vector<int>> seen(
            grid.size(),
            vector<int>(grid[0].size()));

        int result = 0;


        for (int i = 0; i < grid.size(); ++i) {
            for (int k = 0; k < grid[i].size(); ++k) {
                if (!grid[i][k] || seen[i][k]) {
                    continue;
                }

                // otherwise, we are looking at a cell with fish
                result = std::max(discoverFishPatch(i, k, grid, seen, directions), result);
            }
        }

        return result;
    }

    int discoverFishPatch(int x, int y, vector<vector<int>>& grid,
        vector<vector<int>>& seen, vector<pair<int, int>>& directions) 
    {
        int fishPatchAmount = grid[x][y];
        queue<pair<int,int>> bfs;
        bfs.push({x,y});
        seen[x][y] = 1;

        while (!bfs.empty()) {
            auto cell = bfs.front();
            bfs.pop();

            for (const auto dir : directions) {
                int new_x = dir.first + cell.first;
                int new_y = dir.second + cell.second;

                if (new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[x].size()) {
                    continue; // out of bounds
                }

                if (!grid[new_x][new_y] || seen[new_x][new_y]) {
                    continue;
                }

                fishPatchAmount += grid[new_x][new_y];
                bfs.push({new_x, new_y});
                seen[new_x][new_y] = 1;
            }
        }

        return fishPatchAmount;
    }
};
