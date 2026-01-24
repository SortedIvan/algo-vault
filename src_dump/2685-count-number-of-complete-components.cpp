class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // first, we build an adjacency list
        std::unordered_map<int, vector<int>> adjacencyList;
        buildAdjacencyList(adjacencyList, edges);

        // we then use dfs to get all connected components
        vector<vector<int>> connectedComponents;
        getAllConnectedComponents(connectedComponents, adjacencyList, n);

        // finally, get how many connected components are complete
        return countCompleteConnectedComponents(connectedComponents, adjacencyList);
    }

    void buildAdjacencyList(std::unordered_map<int, std::vector<int>>& adjacencyList,
                            vector<vector<int>>& edges) {
        for (vector<int>& edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }
    }

    void getAllConnectedComponents(vector<vector<int>>& connectedComponents,
                                   std::unordered_map<int, std::vector<int>>& adjacencyList,
                                   int n) {
        std::unordered_set<int> processed;
        
        for (int i = 0; i < n; ++i) {
            
            if (processed.find(i) != processed.end()) {
                continue;
            }

            std::stack<int> dfs;
            vector<int> connectedComponent;

            dfs.push(i);
            processed.insert(i);
            connectedComponent.push_back(i);

            while (!dfs.empty()) {
                int vertex = dfs.top();
                dfs.pop();
                
                for (const int &next : adjacencyList[vertex]) {
                    if (processed.find(next) != processed.end()) {
                        continue;
                    }
                    
                    connectedComponent.push_back(next);
                    dfs.push(next);
                    processed.insert(next);
                }
            }

            connectedComponents.push_back(connectedComponent);
        }
    }

    int countCompleteConnectedComponents(vector<vector<int>>& connectedComponents,
                            unordered_map<int, vector<int>>& adjacencyList) {
        // a connected component is complete if it has an adge between each vertex
        // this means that for every vertex in a component, it must have 
        // component.size() - 1 edges
        int completeConnectedComponentsCount = 0;

        for (vector<int>& connectedComponent : connectedComponents) {
            bool isComplete = true;
            int mustHaveNumberOfEdges = connectedComponent.size() - 1;

            for (int i = 0; i < connectedComponent.size(); ++i) {
                int vertex = connectedComponent[i];
                if (adjacencyList[vertex].size() != mustHaveNumberOfEdges) {
                    isComplete = false;
                    break;
                }
            }

            if (isComplete) completeConnectedComponentsCount++;
        }

        return completeConnectedComponentsCount;
    }
};
