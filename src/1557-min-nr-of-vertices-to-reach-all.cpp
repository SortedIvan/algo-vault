class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // dumb solution => find all nodes that do not have any incoming edges XD
        // I definitely came up with this on the first try (cap)
        
        unordered_set<int> verticesWithoutIncomingEdges;
        vector<int> result;

        for (int i = 0; i < edges.size(); ++i) {
            verticesWithoutIncomingEdges.insert(edges[i][0]);
            verticesWithoutIncomingEdges.insert(edges[i][1]);
        }


        for (int i = 0; i < edges.size(); ++i) {
            if (verticesWithoutIncomingEdges.find(edges[i][1]) != verticesWithoutIncomingEdges.end()) {
                verticesWithoutIncomingEdges.erase(edges[i][1]);
            }
        }

        result.insert(result.end(), verticesWithoutIncomingEdges.begin(), 
                      verticesWithoutIncomingEdges.end());

        return result;
    }
};
