class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        bool endExists = false;
        for (int i = 0; i < bank.size(); ++i) {
            if (bank[i] == endGene) {
                endExists = true;
                break;
            }
        }

        if (!endExists) {
            return -1;
        }

        unordered_map<string, vector<string>> adjList = createAdjacencyList(startGene, endGene, bank);

        // After we build the adjacency list, we just need to do a BFS traversal on the graph to find
        // the shortest path

        return findShortestGeneticMutation(startGene, endGene, adjList);
    }

    int findShortestGeneticMutation(string start, string end, unordered_map<string, vector<string>>& adjList) {
        unordered_set<string> visited;
        queue<pair<int, string>> bfs;

        visited.insert(start);
        bfs.push({0, start});
        

        while (!bfs.empty()) {
            auto node = bfs.front();
            bfs.pop(); 

            if (node.second == end) {
                return node.first;
            }

            for (int i = 0; i < adjList[node.second].size(); ++i) {
                if (visited.find(adjList[node.second][i]) == visited.end()) {
                    visited.insert(adjList[node.second][i]);
                    bfs.push({node.first + 1,adjList[node.second][i]});
                }
            }
        }

        return -1;
    }

    unordered_map<string, vector<string>> createAdjacencyList(string startGene, string endGene, 
        vector<string> bank) {
        unordered_map<string, vector<string>> adjacencyList;

        bank.push_back(startGene); 

        for (int i = 0; i < bank.size(); ++i) {
            for (int k = 0; k < bank.size(); ++k) {
                if (i == k) {
                    continue;
                }

                if (isValidTransition(bank[i], bank[k])) {
                    adjacencyList[bank[i]].push_back(bank[k]);
                }
            }
        }

        return adjacencyList;
    }

    bool isValidTransition(string geneOne, string geneTwo) {
        int pointer = 0;
        int diffCharsAmount = 0;

        while (pointer < geneOne.size()) {
            if (geneOne[pointer] != geneTwo[pointer]) {
                diffCharsAmount++;
            }

            if (diffCharsAmount > 1) {
                return false;
            }

            pointer++;
        }

        return diffCharsAmount == 1;
    }
};
