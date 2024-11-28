class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> sums;
        unordered_map<int, vector<int>> nodeMap;

        for (int i = 0; i < edges.size(); ++i) {
            int x = edges[i][0];
            int y = edges[i][1];
            nodeMap[x].push_back(y);
            nodeMap[y].push_back(x);
        }

        for (int i = 0; i < n; ++i) {
            sums.push_back(findTotalDistances(i, nodeMap));
        }

        return sums;
    }

    int findTotalDistances(int node, unordered_map<int, vector<int>>& nodeMap) {
        int distance = 0;
        unordered_set<int> visited;
        queue<pair<int,int>> bfs;
        bfs.push({0, node});

        while (!bfs.empty()) {
            auto x = bfs.front();
            bfs.pop();
            visited.insert(x.second);
            distance = distance + x.first;

            for (int i = 0; i < nodeMap[x.second].size(); ++i) {
                if (visited.find(nodeMap[x.second][i]) != visited.end()) {
                    continue;
                }

                bfs.push({x.first + 1,nodeMap[x.second][i]});
            }
        }

        return distance;
    }
};
