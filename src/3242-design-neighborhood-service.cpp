class NeighborSum {
private:
    vector<vector<int>> grid;
    unordered_map<int, vector<int>> sumMap;
    vector<pair<int,int>> directions = {
        {1,0}, {-1, 0}, {0,1}, {0, -1},
        {1,1}, {-1, -1}, {1,-1}, {-1, 1}
    };

    void calculateAllSums() {
        for (int i = 0; i < grid.size(); ++i) {
            for (int k = 0; k < grid.size(); ++k) {
                calculateSum(i, k, grid[i][k]);
            }
        }
    }

    void calculateSum(int x, int y, int nr) {
        int adjacentSum = 0;
        int diagonalSum = 0;

        for (int i = 0; i < directions.size(); ++i) {
            int new_x = x + directions[i].first;
            int new_y = y + directions[i].second;

            if (new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[x].size()) {
                continue;
            }

            if (i < 4) {
                adjacentSum += grid[new_x][new_y];  
            } else {
                diagonalSum += grid[new_x][new_y]; 
            }
        }

        sumMap[nr].push_back(adjacentSum);
        sumMap[nr].push_back(diagonalSum);
    }

public:
    NeighborSum(vector<vector<int>>& grid) {
        this->grid = grid;
        calculateAllSums();
    }
    
    int adjacentSum(int value) {
        return sumMap[value][0];
    }
    
    int diagonalSum(int value) {
        return sumMap[value][1];
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
