/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> dfs;
        dfs.push(root);

        if (root == q || root == p) {
            return root;
        }

        while (!dfs.empty()) {
            TreeNode* newRoot = dfs.top();
            dfs.pop();
            
            int left = countNodesUnderGivenRoot(newRoot->left, p , q);
            int right = countNodesUnderGivenRoot(newRoot->right, p, q);

            if (left == 2) {
                dfs.push(newRoot->left);
            }
            else if (right == 2) {
                dfs.push(newRoot->right);
            }
            else {
                // its 1 in left 1 in right, we have to return root
                return newRoot;
            }
        }

        return nullptr;
    }

    int countNodesUnderGivenRoot(TreeNode* root, TreeNode* p, TreeNode* q) {
        int count = 0;
        stack<TreeNode*> dfs;
        dfs.push(root);

        while (!dfs.empty()) {
            TreeNode* node = dfs.top();
            dfs.pop();

            if (!node) {
                continue;
            }

            if (node == p || node == q) {
                count++;
            }

            if (node->left) {
                dfs.push(node->left);
            }

            if (node->right) {
                dfs.push(node->right);
            }
        }

        return count;
    }
};
