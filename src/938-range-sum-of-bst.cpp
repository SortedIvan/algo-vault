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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        collectSum(sum, root, low, high);
        return sum;
    }

    void collectSum(int& sum, TreeNode* root, int& low, int& high) {
        if (!root) {
            return;
        }

        if (low <= root->val && root->val <= high) {
            sum += root->val;
            
            collectSum(sum, root->left, low, high);
            collectSum(sum, root->right, low, high);
        } else if (low > root->val) {
            collectSum(sum, root->right, low, high);
        } else if (high < root->val) {
            collectSum(sum, root->left, low,high);
        }
    }
};
