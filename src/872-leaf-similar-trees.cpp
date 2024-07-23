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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        if (!root1 && !root2) {
            return true;
        }

        if (!root1 && root2 || !root2 && root1) {
            return false;
        }
        
        vector<int> leavesOne;
        vector<int> leavesTwo;
        collectLeaves(root1, leavesOne);
        collectLeaves(root2, leavesTwo);

        if (leavesOne.size() != leavesTwo.size()) {
            return false;
        }

        for (int i = 0; i < leavesOne.size(); ++i) {
            if (leavesOne[i] != leavesTwo[i]) {
                return false;
            }
        }

        return true;
    }

    void collectLeaves(TreeNode* root, vector<int>& leaves) {
        if (!root) {
            return;
        }

        if (root->left) {
            collectLeaves(root->left, leaves);
        }

        if (root->right) {
            collectLeaves(root->right, leaves);
        }

        if (!root->left && !root->right) {
            leaves.push_back(root->val);
        }
    }
};
