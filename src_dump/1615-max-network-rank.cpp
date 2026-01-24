class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        std::unordered_map<int, std::unordered_set<int>> roadMap;

        for (vector<int>& road : roads) {
            roadMap[road[0]].insert(road[1]);
            roadMap[road[1]].insert(road[0]);
        }

        int maxNetworkRank = 0;

        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n; ++k) {
                if (i == k) {continue;}

                int contenderNetworkRank = 0;

                // if they both contain eachother, we have to remove one
                if (roadMap[i].find(k) != roadMap[i].end() &&
                    roadMap[k].find(i) != roadMap[k].end()) {
                        contenderNetworkRank = roadMap[i].size() + roadMap[k].size() - 1;
                }
                else {
                    contenderNetworkRank = roadMap[i].size() + roadMap[k].size();
                }

                maxNetworkRank = std::max(maxNetworkRank, contenderNetworkRank);
            }
        }

        return maxNetworkRank;
    }
};
