class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int specialPositionCounter = 0;
        vector<pair<int,int>> directions = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < mat.size(); ++i) {
            for (int k = 0; k < mat[i].size(); ++k) {
                if (mat[i][k]) {
                    checkSpecialPosition(i, k, mat, specialPositionCounter, directions);
                }
            }
        }

        return specialPositionCounter;
    }

    void checkSpecialPosition(int x, int y, vector<vector<int>>& mat, int& specialPositionCounter, vector<pair<int,int>>& directions) {
        for (int i = 0; i < directions.size(); ++i) {
            pair<int,int> dir = directions[i];
            int copy_x = x;
            int copy_y = y;
            bool directionOk = true;

            while (true) {
                int new_x = copy_x + dir.first;
                int new_y = copy_y + dir.second;

                if (new_x < 0 || new_x >= mat.size() || new_y < 0 || new_y >= mat[x].size()) {
                    directionOk = true;
                    break;
                }

                if (mat[new_x][new_y]) {
                    directionOk = false;
                    break;
                }

                copy_x = new_x;
                copy_y = new_y;
            }

            if (!directionOk) {
                return;
            }
        }

        specialPositionCounter++;
    }


};
