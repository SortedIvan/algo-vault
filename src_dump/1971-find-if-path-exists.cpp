class UnionFind {
private:
    vector<int> parent;
    vector<int> size;
public:
    UnionFind(int n) {
        for (int i = 0; i < n; ++i) {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    void Union(int a, int b) { // unions two groups
        int parentA = Find(a);
        int parentB = Find(b);

        if (parentA == parentB) {
            return;
        }

        if (size[parentA] > size[parentB]) {
            parent[parentB] = parentA;
            size[parentA] += size[parentB];
        } else {
            parent[parentA] = parentB;
            size[parentB] += size[parentA];
        }
    } 

    int Find(int a) {  // finds a node parent
        while (a != parent[a]) {
            a = parent[a];
        }

        return a;
    }

};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // 1) Build Union Find
        // 2) Check if two nodes have the same parent
        UnionFind uf = UnionFind(n);

        for (int i = 0; i < edges.size(); ++i) {
            int v1 = edges[i][0];
            int v2 = edges[i][1];

            if ((v1 == source && v2 == destination) || (v1 == destination && v2 == source)) {
                return true; // check for early returns
            }

            uf.Union(v1, v2);
        }

        int parentA = uf.Find(source);
        int parentB = uf.Find(destination);

        return (parentA == parentB);
    }
};
