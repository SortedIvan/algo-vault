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
    vector<int> preorder(Node* root) {
        // pre order traversal
        // root -> left -> right

        vector<int> result;
        traverse(result, root);
        return result;
    }

    void traverse(vector<int>& result, Node* root) {
        if (!root) {
            return;
        }

        result.push_back(root->val);
        
        for (int i = 0; i < root->children.size(); ++i) {
            traverse(result, root->children[i]);
        }
    }
};
