class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        pair<int,int> firstMin = {std::numeric_limits<int>::max(),-1};
        pair<int,int> secondMin = {std::numeric_limits<int>::max(), -1};
        pair<int,int> firstMax = {std::numeric_limits<int>::min(), -1};
        pair<int,int> secondMax = {std::numeric_limits<int>::min(), -1};

        for (int i = 0; i < arrays.size(); ++i) {
            if (arrays[i][0] < firstMin.first) {
                firstMin = {arrays[i][0], i};
            }

            if (arrays[i][arrays[i].size() - 1] > firstMax.first) {
                firstMax = {arrays[i][arrays[i].size() - 1], i};
            }
        }
        
        if (firstMin.second != firstMax.second) {
            return std::abs(firstMin.first - firstMax.first);
        }

        for (int i = 0; i < arrays.size(); ++i) {
            if (arrays[i][0] < secondMin.first && firstMin.second != i) {
                secondMin = {arrays[i][0], i};
            }

            if (arrays[i][arrays[i].size() - 1] > secondMax.first && firstMax.second != i) {
                secondMax = {arrays[i][arrays[i].size() - 1], i};
            }
        }

        int alternative1 = std::abs(firstMin.first - secondMax.first);
        int alternative2 = std::abs(firstMax.first - secondMin.first);

        return std::max(alternative1, alternative2);
    }
};
