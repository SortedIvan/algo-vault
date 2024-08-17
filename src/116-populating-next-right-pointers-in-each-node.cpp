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
        unordered_map<int, vector<Node*>> nodes; 
        collectNodesPerLevel(0, nodes, root);
        
        for(auto level : nodes) {
            for (int i = 0; i < level.second.size() - 1; ++i) {
                level.second[i]->next = level.second[i+1];
            }
        }

        return root;
    }

    void collectNodesPerLevel(int currentLevel,unordered_map<int, vector<Node*>>& nodes, Node* root) {
        if (!root) {
            return;
        }

        nodes[currentLevel].push_back(std::move(root));

        if (root->left) {
            collectNodesPerLevel(currentLevel + 1, nodes, root->left);
        }

        if (root->right) {
            collectNodesPerLevel(currentLevel + 1, nodes, root->right);
        }
    }
};
