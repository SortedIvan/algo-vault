class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> roadConnections;

        // collect all roads into the unordered set
        for (int i = 0; i < roads.size(); ++i) {
            if (roadConnections.find(roads[i][0]) != roadConnections.end()) {
                roadConnections[roads[i][0]]++;
            } else {
                roadConnections.insert({roads[i][0], 1});
            }

            if (roadConnections.find(roads[i][1]) != roadConnections.end()) {
                roadConnections[roads[i][1]]++;
            } else {
                roadConnections.insert({roads[i][1], 1});
            }
        }

        priority_queue<pair<int, int>> roadImportanceQueue;

        for (auto pair : roadConnections) {
            roadImportanceQueue.push({pair.second, pair.first});
        }

        vector<int> importanceValues(n);

        while (!roadImportanceQueue.empty()) {
            auto pair = roadImportanceQueue.top();
            roadImportanceQueue.pop();
            importanceValues[pair.second] = n;
            n--;
        }

        set<pair<int,int>> processed;

        long long totalSum = 0;

        for (int i = 0; i < roads.size(); ++i) {
            if (processed.count({roads[i][0], roads[i][1]}) || processed.count({roads[i][1], roads[i][0]})) {
                continue;
            }

            processed.insert({roads[i][0], roads[i][1]});
            processed.insert({roads[i][1], roads[i][0]});

            totalSum += importanceValues[roads[i][0]] + importanceValues[roads[i][1]];
        }

        return totalSum;
    }
};
