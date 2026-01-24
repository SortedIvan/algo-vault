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
    int diameterOfBinaryTree(TreeNode* root) {
        
        if (!root)
        {
            return 0;
        }

        int max = 0;

        getMaxHeight(root, max);
       
        return max;
    }

    void getMaxHeight(TreeNode* root, int& max)
    {
        if (!root)
        {
            return;
        }

        int leftHeight = 0;
        int rightHeight = 0;

        leftHeight = height(root->left);

        rightHeight = height(root->right);

        if ((leftHeight + rightHeight) > max)
        {
            max = leftHeight + rightHeight;
        }

        getMaxHeight(root->left, max);
        getMaxHeight(root->right, max);
    }

    int height(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }

        return std::max(height(root->left), height(root->right)) + 1;
    }
};
