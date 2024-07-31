/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {

        if (!root) {
            return nullptr;
        }

        // post-order traversal
        TreeNode* parent = nullptr;
        removeNodesWithDfs(root, parent, false, target);

        if (root->val == target && !root->left && !root->right) {
            return nullptr;
        } 

        return root;
    }

    void removeNodesWithDfs(TreeNode* root, TreeNode*& parent, bool leftChild, int target) {
        if (root->left) {
            removeNodesWithDfs(root->left, root,true, target);
        }

        if (root->right) {
            removeNodesWithDfs(root->right, root,false ,target);
        }

        if (!parent) {
            return;
        }

        if (!root->left && !root->right) {
            if (root->val == target) {
                if (leftChild) {
                    parent->left = nullptr;
                } else {
                    parent->right = nullptr;
                }
            }
        }
    }
}; 
