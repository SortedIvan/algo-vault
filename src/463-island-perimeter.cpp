class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int k = 0; k < grid[i].size(); ++k) {
                if (grid[i][k]) {
                    return getIslandPerimeter(grid, i, k);   
                }
            }
        }

        return 0;
    }

    int getIslandPerimeter(vector<vector<int>>& grid, int x, int y) {
        pair<int,int> directions[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int perimeter = 0;
        vector<vector<int>> seen;
        for (int i = 0; i < grid.size(); ++i) {
            vector<int> row;
            
            for (int k = 0; k < grid[i].size(); ++k) {
                row.push_back(0);
            }

            seen.push_back(row);
        }

        pair<int,int> start = {x, y};
        queue<pair<int,int>> bfs;
        bfs.push(start);
        seen[x][y] = 1;

        while (!bfs.empty()) {
            pair<int,int> current = bfs.front();
            bfs.pop();

            for (int i = 0; i < 4; ++i) {
                pair<int,int> direction = directions[i];
                int newX = current.first + direction.first;
                int newY = current.second + direction.second;
                
                if (newX < 0 || newX == grid.size()) {
                    perimeter++;
                }

                if (newY < 0 || newY == grid[current.first].size()) {
                    perimeter++;
                }

                if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[current.first].size()) {
                    if (grid[newX][newY]) {
                        if (!seen[newX][newY]) {
                            bfs.push({newX, newY});
                            seen[newX][newY] = 1;
                        }
                    }
                    else {
                        perimeter++;
                    }
                }
            }

        }

        return perimeter;
    }
};
