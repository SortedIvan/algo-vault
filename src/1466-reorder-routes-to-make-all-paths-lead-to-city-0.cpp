class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // 1) first, make into adjaceny map
        std::unordered_map<int, vector<int>> realMap;
        std::unordered_map<int, vector<int>> biDirectional;
        for (int i = 0; i < connections.size(); ++i) {
            vector<int> conn = connections[i];
            realMap[conn[0]].push_back(conn[1]);
        }

        for (int i = 0; i < connections.size(); ++i) {
            vector<int> conn = connections[i];
            biDirectional[conn[0]].push_back(conn[1]);
            biDirectional[conn[1]].push_back(conn[0]);
        }

        // 2) run bfs and re-order roads
        // since the graph is a tree:
        // - add all nodes into a bi-directional list
        // - add all nodes into a single directional list
        // start from 0 => if path currElement <- newElement does not exist in single directional, ++
        // else, use the bi-directional to traverse to other potential elements & continue
        
        int counter = 0;
        fixRoads(realMap, biDirectional, 0, counter, -1);
        return counter;
    }

    void fixRoads(std::unordered_map<int, vector<int>>& realMap, std::unordered_map<int, vector<int>>& biDirectional, int currNode, int& counter,int prevNode) {
        for (int node : biDirectional[currNode]) { 
            if (node == prevNode) {
                continue;
            }

            // check for node -> currNode
            bool found = false;
            for (int i = 0; i < realMap[node].size(); ++i) {
                if (realMap[node][i] == currNode) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                counter++;
            }

            fixRoads(realMap, biDirectional, node, counter, currNode);
        }
    }

};
