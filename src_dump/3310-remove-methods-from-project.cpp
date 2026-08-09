class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        std::unordered_map<int, std::vector<int>> methodMap;

        // 1. Build the invocation map, this will create graph/s
        for (int i = 0; i < invocations.size(); ++i) {
            const vector<int>& methodCall = invocations[i];
            methodMap[methodCall[0]].push_back(methodCall[1]);
        }

        // 2. Identify the suspicious method group
        std::unordered_set<int> suspiciousMethods;
        std::unordered_set<int> processed;
        std::queue<int> bfs;
        bfs.push(k);
        processed.insert(k);
        suspiciousMethods.insert(k);

        while (!bfs.empty()) {
            int next = bfs.front();
            bfs.pop();

            // for all of the invoked methods
            for (int i = 0; i < methodMap[next].size(); ++i) {
                int childMethod = methodMap[next][i];

                if (processed.find(childMethod) != processed.end()) {
                    continue;
                }

                processed.insert(childMethod);
                bfs.push(childMethod);
                suspiciousMethods.insert(childMethod);
            }
        }

        std::vector<int> result;
        // Check -> for every invocation a->b, is there an invocation where a is not in the sus group, but b is?
        for (int i = 0; i < invocations.size(); ++i) {
            const int a = invocations[i][0];
            const int b = invocations[i][1];

            bool bIsSus = suspiciousMethods.find(b) != suspiciousMethods.end();
            bool aIsNotSus = suspiciousMethods.find(a) == suspiciousMethods.end();

            if (bIsSus && aIsNotSus) {
                for (int i = 0; i < n; ++i) {
                    result.push_back(i);
                }

                return result;
            } 

            // otherwise, continue;
        }

        // remove all sus methods from the rest
        for (int i = 0; i < n; ++i) {
            if (suspiciousMethods.find(i) == suspiciousMethods.end()) {
                result.push_back(i);
            }
        }

        return result;
    }
};
