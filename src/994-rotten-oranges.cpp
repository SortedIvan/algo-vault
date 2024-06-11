class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<std::tuple<int, int, int>> bfs;
        map<pair<int,int>, int> seen;

        // discover all of the rotten oranges
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    std::tuple<int,int,int> rottenOrange;
                 
                    std::get<0>(rottenOrange) = i;
                    std::get<1>(rottenOrange) = j;
                    std::get<2>(rottenOrange) = 0;

                    bfs.push(rottenOrange);
                }
            }
        }

        int counter = 0;

        while (!bfs.empty()) {
            std::tuple<int,int,int> rottenOrange = bfs.front();
            bfs.pop();
            seen.insert({{std::get<0>(rottenOrange), std::get<1>(rottenOrange)}, 1});

            int x = std::get<0>(rottenOrange);
            int y = std::get<1>(rottenOrange);
            int timeElapsed = std::get<2>(rottenOrange);

            if (timeElapsed > counter) {
                counter++;
            }
            
            if (x - 1 >= 0) {
                if (grid[x-1][y] == 1 && seen.find({x-1, y}) == seen.end()) {
                    std::tuple<int,int,int> rottenOrange;
                 
                    std::get<0>(rottenOrange) = x-1;
                    std::get<1>(rottenOrange) = y;
                    std::get<2>(rottenOrange) = counter + 1;

                    bfs.push(rottenOrange);
                    grid[x-1][y] = 2;
                }
            }

            if (x +1 < grid.size()) {
                if (grid[x+1][y] == 1 && seen.find({x+1, y}) == seen.end()) {
                    std::get<0>(rottenOrange) = x+1;
                    std::get<1>(rottenOrange) = y;
                    std::get<2>(rottenOrange) = counter + 1;

                    bfs.push(rottenOrange);
                    grid[x+1][y] = 2;
                }
            }

            if (y - 1 >= 0) {
                if (grid[x][y-1] == 1 && seen.find({x, y-1}) == seen.end()) {
                    std::get<0>(rottenOrange) = x;
                    std::get<1>(rottenOrange) = y-1;
                    std::get<2>(rottenOrange) = counter + 1;

                    bfs.push(rottenOrange);
                    grid[x][y-1] = 2;
                }
            }

            if (y + 1 < grid[x].size()) {
                if (grid[x][y + 1] == 1 && seen.find({x, y+1}) == seen.end()) {
                    std::get<0>(rottenOrange) = x;
                    std::get<1>(rottenOrange) = y+1;
                    std::get<2>(rottenOrange) = counter + 1;

                    bfs.push(rottenOrange);
                    grid[x][y+1] = 2;
                }
            }
        }

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return counter;
    }
};
