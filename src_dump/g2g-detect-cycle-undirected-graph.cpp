class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> seen(V, 0);
        for (int i = 0; i < V; ++i) {
            
            if (seen[i]) {
                continue;
            }
            
            if (checkForCycle(V, adj, i, seen)) {
                return true;
            }
        }
        
        return false;
    }
    
    bool checkForCycle(int V, vector<int>* adj, int node, vector<int>& seen) {
        stack<pair<int,int>> dfs;
        dfs.push({node, -1}); // the node and its parent, at first -1
        seen[node] = 1;
        
        while (!dfs.empty()) {
            pair<int,int> x = dfs.top();
            dfs.pop();
            
            for (int i = 0; i < adj[x.first].size(); ++i) {
                if (seen[adj[x.first][i]]) {
                    if (x.second == adj[x.first][i]) {
                        continue;
                    }
                    
                    return true;
                }
                
                seen[adj[x.first][i]] = 1;
                dfs.push({adj[x.first][i], x.first});
            }
        }
        
        return false;
    }
};
