class UnionFind {
private:
    std::unordered_map<int, int> parentMap;
public:
    UnionFind(const int n) {
        for (int i = 0; i < n; ++i) {
            parentMap[i] = i;
        } 
    }

    // Try to find the representative of the group
    int find(int x) {
        if (parentMap.find(x) == parentMap.end()) {
            return -1;
        }

        if (parentMap[x] != x) {
            parentMap[x] = find(parentMap[x]);
        }
        return parentMap[x];
    }

    void union_elements(int x, int y) {
        // make y a child of x if they don't exist
        int parent_x = find(x);
        int parent_y = find(y);

        if (parent_x < 0 && parent_y < 0) {
            parentMap[y] = x;
            parentMap[x] = x;
            return;
        }

        if (parent_x < 0 && parent_y >= 0) {
            parentMap[x] = parent_y;
        }
        else if (parent_x >=0 && parent_y < 0) {
            parentMap[y] = parent_x;
        }
        else {
            // Since we don't care for rank, just assign x arbitrarily
            parentMap[parent_y] = parent_x;
        }
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // check if enough cables first
        if (connections.size() < n - 1) {
            return -1;
        }

        // Create adjacency list
        std::unordered_map<int, std::vector<int>> adjMap;

        for (int i = 0; i < connections.size(); ++i) {
            adjMap[connections[i][0]].push_back(connections[i][1]);
            adjMap[connections[i][1]].push_back(connections[i][0]);
        }

        // Since we know there are enough cables, we can just count the connected components
        // and then treat those as individual nodes

        UnionFind uf(n);

        for (int i = 0; i < connections.size(); ++i) {
            uf.union_elements(connections[i][0], connections[i][1]);
        }

        std::unordered_set<int> uniqueComponents;

        for (int i = 0; i < n; ++i) {
            uniqueComponents.insert(uf.find(i));
        }
       
        return uniqueComponents.size() - 1;
    }
};
