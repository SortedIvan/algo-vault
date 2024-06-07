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
        
        std::queue<Node*> bfs;
        std::unordered_map<int, Node*> seen;
        bfs.push(node);

        Node* first = new Node();
        first->val = node->val;
        seen.insert({first->val, first});

        while (!bfs.empty()) {
            
            Node* front = bfs.front();
            bfs.pop();

            for (int i = 0; i < front->neighbors.size(); ++i) {
                if (seen.find(front->neighbors[i]->val) == seen.end()) {
                    Node* add = new Node();
                    add->val = front->neighbors[i]->val;
                    seen.insert({add->val, add});

                    bfs.push(front->neighbors[i]);
                }

                seen[front->val]->neighbors.push_back(seen[front->neighbors[i]->val]);
            }
            

        }

        return seen[1];
    }
};
