class Solution {
private:
    std::unordered_map<int, vector<int>> cacheKnownPaths;

    bool checkIfPathExists(int nodeA, int nodeB,  std::unordered_map<int, vector<int>>& adjMap) {
        std::unordered_set<int> visited;
        std::stack<int> nodes;

        nodes.push(nodeA);

        while (!nodes.empty()) {
            int nodeToProcess = nodes.top();
            nodes.pop();

            if (visited.find(nodeToProcess) != visited.end()) {
                continue;
            }

            visited.insert(nodeToProcess);

            if (nodeToProcess == nodeB) {
                return true;
            }

            // process connections
            for (int i = 0; i < adjMap[nodeToProcess].size(); ++i) {
                int nodeConnection = adjMap[nodeToProcess][i];

                if (visited.find(nodeConnection) != visited.end()) {
                    continue;
                }

                // try to early return here too
                if (nodeConnection == nodeB) {
                    return true;
                }

                nodes.push(nodeConnection);
            }
        }
        
        return false;
    }
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        std::unordered_map<int, vector<int>> adjMap;
        std::vector<bool> result;

        for (int i = 0; i < nums.size(); ++i) {
            for (int k = i; k < nums.size(); ++k) {
                if (i == k) {
                    continue;
                }

                int diff = std::abs(nums[i] - nums[k]);

                if (diff <= maxDiff) {
                    // valid edge between vertex i and k
                    adjMap[k].push_back(i);
                    adjMap[i].push_back(k);
                    continue;
                }

                // otherwise, we have reached a diff thats too big, so we need to break the loop and move to the next element
                break;
            }
        }

        for (int i = 0; i < queries.size(); ++i) {
            if (queries[i][0] == queries[i][1]) {
                // trivial case, true
                result.push_back(true);
                continue;
            }

            if (cacheKnownPaths.find(queries[i][0]) != cacheKnownPaths.end()) {
                bool hadCacheHit = false;

                for (int k = 0; k < cacheKnownPaths[queries[i][0]].size(); ++k) {
                    if (cacheKnownPaths[queries[i][0]][k] == queries[i][1]) {
                        // cacheKnownPaths hit
                        hadCacheHit = true;
                        break;
                    }
                }
                
                if (hadCacheHit) {
                    result.push_back(true);
                    continue;
                }
            }

            bool pathFindingResult = checkIfPathExists(queries[i][0], queries[i][1], adjMap);

            if (pathFindingResult) {
                cacheKnownPaths[queries[i][0]].push_back(queries[i][1]);
                cacheKnownPaths[queries[i][1]].push_back(queries[i][0]);
            }

            result.push_back(pathFindingResult);
        }

        return result;
    }

    
};
