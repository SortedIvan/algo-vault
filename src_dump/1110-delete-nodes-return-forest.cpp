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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (!root) {
            return vector<TreeNode*>();
        }
        
        set<int> numMap;

        for (int i = 0; i < to_delete.size(); ++i) {
            numMap.insert(to_delete[i]);
        }

        vector<TreeNode*> result;
        TreeNode* parent = nullptr;
        dfs(root, parent, false, numMap, result);

        if (root && numMap.find(root->val) == numMap.end()) {
            result.push_back(root);
        }

        return result;
    }

    // DFS, post order
    void dfs(TreeNode*& root, TreeNode*& parent, bool direction, set<int>& numMap, vector<TreeNode*>& result) {
        if (!root) {
            return;
        }

        if (root->left) {
            dfs(root->left, root, false,numMap, result);
        }

        if (root->right) {
            dfs(root->right, root,true, numMap, result);
        }

        if (numMap.find(root->val) != numMap.end()) {

            if (root->left) {
                result.push_back(root->left);
            }

            if (root->right) {
                result.push_back(root->right);
            }

            if (!parent) {
                return;
            }

            if (!direction) {
                // left
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
        }

    }
};
