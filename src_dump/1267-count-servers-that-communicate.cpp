class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        // basically, count all component counts for connected components of length > 1
        vector<vector<int>> seen = initializeEmptyMatrix(grid.size(), grid[0].size());
        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0, 1}, {0, -1}};
        int connectedServers = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int k = 0; k < grid[i].size(); ++k) {
                if (grid[i][k] && !seen[i][k]) {    
                    traverseAndCountServers(grid, i + directions[0].first,
                    k + directions[0].second, seen, directions, connectedServers, 0);

                    traverseAndCountServers(grid, i + directions[1].first,
                    k + directions[1].second,seen,  directions, connectedServers, 1);

                    traverseAndCountServers(grid, i + directions[2].first,
                    k + directions[2].second,seen,  directions, connectedServers, 2);

                    traverseAndCountServers(grid, i + directions[3].first,
                    k + directions[3].second,seen, directions, connectedServers, 3);
                }
            }
        }

        return connectedServers; 
    }

    void traverseAndCountServers(vector<vector<int>>& grid, int x, int y, 
                                vector<vector<int>>& seen, 
                                const vector<pair<int,int>>& directions, 
                                int& connectedServersCounter,
                                int currDirection) 
    {

        if (x < 0 || x >= grid.size() || y < 0 
        || y >= grid[0].size()) {
            return;
        }

        if (seen[x][y]) {
            return;
        }

        if (grid[x][y] == 0) {
            traverseAndCountServers(grid, x + directions[currDirection].first,
                                          y + directions[currDirection].second, seen,
                                          directions, connectedServersCounter, currDirection);
        }
        else {
            
            seen[x][y] = 1;
            connectedServersCounter++;

            traverseAndCountServers(grid, x + directions[0].first,
            y + directions[0].second,seen, directions, connectedServersCounter, 0);

            traverseAndCountServers(grid, x + directions[1].first,
            y + directions[1].second,seen, directions, connectedServersCounter, 1);

            traverseAndCountServers(grid, x + directions[2].first,
            y + directions[2].second,seen, directions, connectedServersCounter, 2);

            traverseAndCountServers(grid, x + directions[3].first,
            y + directions[3].second,seen, directions, connectedServersCounter, 3);
        }
    }
    
    vector<vector<int>> initializeEmptyMatrix(int x, int y) {
        vector<vector<int>> result;
        for (int i = 0; i < x; ++i) {
            vector<int> row;
            for (int k = 0; k < y; ++k) {
                row.push_back(0);
            }
            result.push_back(row);
        }
        return result;
    } 
};
