class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<int>> seen;
        vector<pair<int,int>> directions = {
            {1,0}, {-1, 0}, {0, 1}, {0, -1}
        };

        // initialize matrix with 0's
        for (int i = 0; i < grid.size(); ++i) {
            vector<int> row;
            for (int k = 0; k < grid[i].size(); ++k) {
                row.push_back(0);
            }
            seen.push_back(row);
        }

        for (int i = 0; i < grid.size(); ++i) {
            for (int k = 0; k < grid[i].size(); ++k) {
                if (!seen[i][k]) {
                    if (checkForCycle(grid, seen, i, k, directions)) {
                        seen[i][k] = 1;
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool checkForCycle(vector<vector<char>>& grid, vector<vector<int>>& seen, int x, int y, vector<pair<int,int>>& directions) {
        char startChar = grid[x][y];
        stack<vector<int>> dfs;
        dfs.push({x, y, 0, -1, -1});  // Push starting node with "no parent" (-1, -1)

        while (!dfs.empty()) {
            vector<int> pos = dfs.top();
            dfs.pop();

            for (const auto& dir : directions) {
                int new_x = pos[0] + dir.first;
                int new_y = pos[1] + dir.second;
                int parent_x = pos[3], parent_y = pos[4];

                if (new_x < 0 || new_x >= grid.size() || 
                    new_y < 0 || new_y >= grid[0].size()) 
                {
                    continue;
                }

                // If already seen and not the parent, it's a cycle
                if (seen[new_x][new_y] && !(new_x == parent_x && new_y == parent_y)
                    && pos[2] + 1 >= 4) {
                    return true;
                }

                if (grid[new_x][new_y] == startChar && !seen[new_x][new_y]) {
                    seen[new_x][new_y] = 1; 
                    dfs.push({new_x, new_y, pos[2] + 1, pos[0], pos[1]});
                }
            }
        }

        return false;
    }

};
