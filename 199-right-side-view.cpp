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
    vector<int> rightSideView(TreeNode* root) {
        
        if (!root) {
            return std::vector<int>();
        }
        
        if (!root->left && !root->right) {
            return std::vector<int> {root->val};
        }

        std::vector<int> levels;
        int level = 0;
        collectValuesIntoVec(level, levels, root);

        return levels;
    }

    void collectValuesIntoVec(int level, std::vector<int>& levels, TreeNode* root) {
        // if the value already exists at the given level, just replace it in the array
        if (levels.size() == level) {
            levels.push_back(root->val);
        }

        if (root->left || root->right) {
            level++;
        }

        if (root->right) {
            collectValuesIntoVec(level, levels, root->right);
        }

        if (root->left) {
            collectValuesIntoVec(level, levels, root->left);
        }
    } 
};
