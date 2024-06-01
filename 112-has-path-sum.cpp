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
    bool hasPathSum(TreeNode* root, int targetSum) { 

        if (!root) {
            return false;
        }

        return findIfSum(root, targetSum, root->val);
    }

    bool findIfSum(TreeNode* root, int targetSum, int currentSum) {

        if ((targetSum == currentSum) && !root->left && !root->right) {
            return true;
        }

        bool sumInLeft = false;
        bool sumInRight = false;

        if (root->left) {
            sumInLeft = findIfSum(root->left, targetSum,currentSum + root->left->val);
        }

        if (root->right) {
            sumInRight = findIfSum(root->right, targetSum ,currentSum + root->right->val);
        }

        return sumInLeft || sumInRight;
    }

};
