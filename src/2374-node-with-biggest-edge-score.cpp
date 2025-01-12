class Solution {
public:
    int edgeScore(vector<int>& edges) {
        // this problem does not require graph traversal at all?
        long max = std::numeric_limits<long>::min();
        int biggestNode = 0;
        vector<long> result(edges.size());
        for (int i = 0; i < edges.size(); ++i) {
            result[edges[i]] += i;
        }

        for (int i = 0; i < result.size(); ++i) {
            if (max < result[i]) {
                biggestNode = i;
                max = result[i];
            }
        }

        return biggestNode;
    }
};
