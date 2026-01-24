class UnionFind {
private:
    map<int,int> indexMap;
    vector<int> parent;
    vector<int> size;
public:
    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        for (int i = 0; i < n; ++i) {
            indexMap[i + 1] = i;
        }
    }

    bool Union(int a, int b) {
        int parentIndexA = Find(a);
        int parentIndexB = Find(b);

        if (parentIndexA == parentIndexB) {
            return true;
        }

        // no cycle, we need to perform union
        
        if (size[parentIndexA] > size[parentIndexB]) {
            parent[parentIndexB] = parentIndexA;
            size[parentIndexA] += size[parentIndexB];
        } else {
            parent[parentIndexA] = parentIndexB;
            size[parentIndexB] += size[parentIndexA];
        }

        return false;
    }

    int Find(int a) {
        int parentIndex = indexMap[a];

        while (parentIndex != parent[parentIndex]) {
            parentIndex = parent[parentIndex];
        }

        return parentIndex;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjacencyList;

        for (int i = 0; i < edges.size(); ++i) {
            int v1 = edges[i][0];
            int v2 = edges[i][1];
            
            adjacencyList[v1].push_back(v2);
            adjacencyList[v2].push_back(v1);
        }

        auto uf = UnionFind(adjacencyList.size());

        pair<int,int> lastRedundant = {-1,-1};

        for (int i = 0; i < edges.size();++i) {
            if (uf.Union(edges[i][0], edges[i][1])) {
                lastRedundant = {edges[i][0], edges[i][1]}; 
            }
        }

        vector<int> result = {lastRedundant.first, lastRedundant.second};

        return result;
    }
};
