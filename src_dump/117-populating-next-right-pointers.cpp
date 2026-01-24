/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if (!root) {
            return nullptr;
        }

        vector<Node*> sameLevelNodes;
        int currLevel = 0;
        queue<pair<int, Node*>> bfs;
        root->next = nullptr;
        bfs.push(std::make_pair(0, root));

        while (!bfs.empty()) {
            pair<int, Node*> node = bfs.front();
            bfs.pop();

            if (node.first > currLevel) {
                for (int i = 0; i < sameLevelNodes.size() - 1; ++i) {
                    sameLevelNodes[i]->next = sameLevelNodes[i+1];
                }
                sameLevelNodes = vector<Node*>();
                sameLevelNodes.push_back(node.second);
                currLevel = node.first;
            } else {
                sameLevelNodes.push_back(node.second);
            }

            if (node.second->left) {
                bfs.push({node.first + 1, node.second->left});
            }

            if (node.second->right) {
                bfs.push({node.first + 1, node.second->right});
            }
        }

        // process any leftover nodes
        if (sameLevelNodes.size() > 0) {
            for (int i = 0; i < sameLevelNodes.size() - 1; ++i) {
                sameLevelNodes[i]->next = sameLevelNodes[i+1];
            }
        }

        return root;
    }
};
