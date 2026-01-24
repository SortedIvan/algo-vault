/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) { 

        if (!node) {
            return nullptr;
        }

        queue<Node*> bfs;
        unordered_map<int, Node*> seen;
        
        Node* first = new Node();
        first->val = node->val;
        seen.insert({first->val, first});

        traverseGraph(seen, node);

        return seen[1];
    }

    void traverseGraph(unordered_map<int, Node*>& seen, Node* curr) {
        for (int i = 0; i < curr->neighbors.size(); ++i) {
            if (seen.find(curr->neighbors[i]->val) == seen.end()) {
                Node* add = new Node();
                add->val = curr->neighbors[i]->val;
                seen.insert({add->val, add});

                traverseGraph(seen, curr->neighbors[i]);
            }

            seen[curr->val]->neighbors.push_back(seen[curr->neighbors[i]->val]);
        }
    }
    
};
