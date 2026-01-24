/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {

        if (!root) {
            return 0;
        }

        int max = 0;
        dfs(max, 0, root);
        return max + 1;
    }

    void dfs(int& max, int current, Node* root) {
        if (!root) {
            return;
        }

        if (root->children.empty()) {
            max = std::max(max, current);
        }
        else {
            for (int i = 0; i < root->children.size(); ++i) {
                dfs(max, current + 1, root->children[i]);
            }
        }
    }
};
