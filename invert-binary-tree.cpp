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
    // idea: 
    // root => if root has left and right, swap.
    // once everything is exhausted, go right and repeat
    // use std::swap() to swap the pointers
    TreeNode* invertTree(TreeNode* root) 
    {
        if (!root)
        {
            return nullptr;
        }

        swapTree(root);

        return root;       
    }

    void swapTree(TreeNode* curr)
    {
        if (curr->left && curr->right)
        {
            std::swap(curr->left, curr->right); 
            swapTree(curr->left);
            swapTree(curr->right);
        }
        else if (curr->left && !curr->right)
        {
            std::swap(curr->left, curr->right);
            swapTree(curr->right);
        }
        else if (curr->right && !curr->left)
        {
            std::swap(curr->left, curr->right);
            swapTree(curr->left);
        }
    }
};
