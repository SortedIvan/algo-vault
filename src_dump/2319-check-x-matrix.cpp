class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        pair<int,int> leftDiagonal = {0,0};
        pair<int,int> rightDiagonal = {0, grid.size() - 1};

        // n x n matrix, coordinates will be: 
        // (0, 0) -> (n - 1, n - 1) with 1,1 increments
        // (0, n - 1) -> (n - 1, 0) with (1,-1) increments

        int totalNonNullDiagonalValues = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int k = 0; k < grid[i].size(); ++k) {
                pair<int,int> currentCoord = {i,k};

                if (currentCoord == leftDiagonal && currentCoord == rightDiagonal) {
                    leftDiagonal = addPairs(leftDiagonal, {1,1});
                    rightDiagonal = addPairs(rightDiagonal, {1, -1});
                    
                    if (grid[i][k] > 0) {
                        totalNonNullDiagonalValues++;
                    }
                    else {
                        return false;
                    }

                    continue;
                }

                if (currentCoord == leftDiagonal) {
                    leftDiagonal = addPairs(leftDiagonal, {1,1});

                    if (grid[i][k] > 0) {
                        totalNonNullDiagonalValues++;
                    }
                    else {
                        return false;
                    }
                }
                else if (currentCoord == rightDiagonal) {
                    rightDiagonal = addPairs(rightDiagonal, {1, -1});

                    if (grid[i][k] > 0) {
                        totalNonNullDiagonalValues++;
                    }
                    else {
                        return false;
                    }
                }
                else {
                    // not a diagonal coordinate, check for other rule
                    if (grid[i][k] != 0) {
                        return false;
                    }
                }
            }
        }

        if (grid.size() % 2 == 0) {
            return totalNonNullDiagonalValues == 2 * grid.size();
        }

        return totalNonNullDiagonalValues == ((2 * grid.size()) - 1);
    }


    /*
        (0,0) -> (1,1) -> (2,2) -> (3, 3)
        (0,3) -> (1,2) -> (2,1) -> (3, 0)
    */

    pair<int,int> addPairs(pair<int,int> p1, pair<int,int> p2) {
        return {
            p1.first + p2.first,
            p1.second + p2.second
        };
    }
};
