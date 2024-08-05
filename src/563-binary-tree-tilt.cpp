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
    int findTilt(TreeNode* root) {
        unordered_map<TreeNode*, pair<int,int>> nodeMap;
        int tiltSum = 0;
        postOrderTraversal(root, nodeMap, tiltSum);
        return tiltSum;
    }

    void postOrderTraversal(TreeNode* root, unordered_map<TreeNode*, pair<int,int>>& nodeMap, int& tiltSum) {
        if (!root) {
            return;
        }

        if (root->left) {
            postOrderTraversal(root->left, nodeMap, tiltSum);
        }

        if (root->right) {
            postOrderTraversal(root->right, nodeMap, tiltSum);
        }

        int leftSum = 0;
        int rightSum = 0;

        if (root->left) {
            leftSum += (root->left->val + nodeMap[root->left].first + nodeMap[root->left].second);
        }

        if (root->right) {
            rightSum += (root->right->val + nodeMap[root->right].first + nodeMap[root->right].second);
        }

        tiltSum += std::abs(leftSum - rightSum);
        nodeMap.insert({root, {leftSum, rightSum}});
    }
};
