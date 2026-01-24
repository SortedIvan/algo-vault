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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = buildBalancedTree(0, nums.size() - 1, nums);
        return root;
    }

    TreeNode* buildBalancedTree(int left, int right, vector<int>& nums) {
        if (left > right) {
            return nullptr;
        }

        int mid = (left + right) / 2;

        TreeNode* root = new TreeNode();
        root->val = nums[mid];

        root->left = buildBalancedTree(left, mid - 1, nums);
        root->right = buildBalancedTree(mid + 1, right, nums);

        return root;
    }
};
