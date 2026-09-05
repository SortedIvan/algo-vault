class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        std::pair<int,int> centerVector = std::make_pair(rCenter, cCenter);
        std::vector<std::vector<int>> positionsWithDistance;
        std::vector<std::vector<int>> result;

        for (int i = 0; i < rows; ++i) {
            for (int k = 0; k < cols; ++k) {
                std::pair<int,int> positionVec = std::make_pair(i, k);

                if (centerVector == positionVec) {
                    positionsWithDistance.push_back(std::vector<int>{centerVector.first, centerVector.second, 0});
                    continue;
                }

                int distance = std::abs(centerVector.first - positionVec.first) + std::abs(centerVector.second - positionVec.second);

                positionsWithDistance.push_back(std::vector<int>{positionVec.first, positionVec.second, distance});
            }
        }

        std::sort(positionsWithDistance.begin(), positionsWithDistance.end(), customSortOperator);

        for (int i = 0; i < positionsWithDistance.size(); ++i) {
            result.push_back(std::vector<int>{positionsWithDistance[i][0], positionsWithDistance[i][1]});
        }

        return result;

    }

    static bool customSortOperator(const std::vector<int>& a, const std::vector<int>& b) {
        return a[2] < b[2];
    }
};
