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
    bool isSymmetric(TreeNode* root) {

        if (!root)
        {
            return true;
        }

        if (!root->left && !root->right)
        {
            return true;
        }

        if ((!root->left && root->right) || (root->left && !root->right))
        {
            return false;
        }

        queue<TreeNode*> left;
        queue<TreeNode*> right;

        left.push(root->left);
        right.push(root->right);

        while (!left.empty() && !right.empty())
        {
            TreeNode* leftNode = left.front();
            TreeNode* rightNode = right.front();

            if ((!leftNode && rightNode) || (leftNode && !rightNode))
            {
                return false;
            } 

            left.pop();
            right.pop();

            if (!leftNode && !rightNode)
            {
                continue;
            }

            if (leftNode->val != rightNode->val)
            {
                return false;
            }

            left.push(leftNode->left);
            right.push(rightNode->right);

            left.push(leftNode->right);
            right.push(rightNode->left);
        }

        if (left.empty() && right.empty())
        {
            return true;
        }

        return false;
    }
};
