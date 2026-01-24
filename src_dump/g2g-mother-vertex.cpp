class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    int smallestMotherIndex = std::numeric_limits<int>::max();
	    for (int i = 0; i < V; ++i) {
	        if (checkIfNodeVisitsAll(V, i, adj)) {
	            smallestMotherIndex = std::min(smallestMotherIndex, i);
	            if (smallestMotherIndex == 0) {
	                return 0;
	            }
	        }
	    }
	    
	    if (smallestMotherIndex == std::numeric_limits<int>::max()) {
	        return -1;
	    }
	    
	    return smallestMotherIndex;
	}
	
    bool checkIfNodeVisitsAll(int v, int node, vector<int>* adj) {
        stack<int> dfs;
        vector<int> seen(v, 0);
        dfs.push(node);
        seen[node] = 1;
        int nodeCounter = 1;    
    
        while (!dfs.empty()) {
            int x = dfs.top();
            dfs.pop();
            
            for (int i = 0; i < adj[x].size(); ++i) {
                if (seen[adj[x][i]]) {
                    continue;
                }
                
                nodeCounter++;
                dfs.push(adj[x][i]);
                seen[adj[x][i]] = 1;
            }        
        }
        
        if (nodeCounter == v) {
            return true;
        }
        
        return false;
    }

};
