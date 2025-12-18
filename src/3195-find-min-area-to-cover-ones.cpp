class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {   
        // first, find the first encountered 1 cols from left -> end and right -> start
        // then, find the first encountered 1 rows from top -> bot and bot -> top

        std::vector<int> coords;

        for (int col = 0; col < grid[0].size(); ++col) {
            for (int row = 0; row < grid.size(); ++row) {
                if (grid[row][col]) {
                    coords.push_back(col);
                    break;
                }
            }

            if (coords.size() == 1) {
                break;
            }
        }
        
        for (int col = grid[0].size() - 1; col >= 0; --col) {
            for (int row = 0; row < grid.size(); ++row) {
                if (grid[row][col]) {
                    coords.push_back(col);
                    break;
                }
            }
            if (coords.size() == 2) {
                break;
            }
        }

        for (int i = 0; i < grid.size(); ++i) {
            for (int k = 0; k < grid[i].size(); ++k) {
                if (grid[i][k]) {
                    coords.push_back(i);
                    break;
                }
            }

            if (coords.size() == 3) {
                break;
            }
        }

        for (int i = grid.size() - 1; i >= 0; --i) {
            for (int k = 0; k < grid[i].size(); ++k) {
                if (grid[i][k]) {
                    coords.push_back(i);
                    break;
                }
            }

            if (coords.size() == 4) {
                break;
            }
        }

        // x1, x2
        // y1, y2

        int width = coords[1] - coords[0];
        int height = coords[3] - coords[2];

        return (width + 1) * (height + 1);
    }
};


// 0, 0, 1, 0, 1
// 0, 1, 0, 0, 1
// 0, 1, 0, 0, 0
// 0, 0, 1, 0, 0
//
