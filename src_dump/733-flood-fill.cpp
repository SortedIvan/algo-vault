class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        fillImage(sr, sc, image, color);
        return image;
    }

    void fillImage(int i, int j, vector<vector<int>>& matrix, int color) {
        int startingColor = matrix[i][j];

        if (startingColor == color) {
            return;
        }

        queue<pair<int,int>> bfs;
        bfs.push({i,j});

        matrix[i][j] = color;

        while (!bfs.empty()) {
            auto front = bfs.front();
            bfs.pop();

            int x = front.first;
            int y = front.second;

            if (x - 1 >= 0) {
                if (matrix[x-1][y] == startingColor) {
                    matrix[x-1][y] = color;
                    bfs.push({x-1,y});
                }
            }

            if (x + 1 < matrix.size()) {
                if (matrix[x+1][y] == startingColor) {
                    matrix[x+1][y] = color;
                    bfs.push({x+1,y});
                }
            }

            if (y - 1 >= 0) {
                if (matrix[x][y-1] == startingColor) {
                    matrix[x][y-1] = color;
                    bfs.push({x,y-1});
                }
            }

            if (y + 1 < matrix[x].size()) {
                if (matrix[x][y+1] == startingColor) {
                    matrix[x][y+1] = color;
                    bfs.push({x,y+1});
                }
            }
        }
    }
};
