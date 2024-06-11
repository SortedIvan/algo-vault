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
    bool isBalanced(TreeNode* root) 
    {
        /*
            The idea: 
            For every node, get the height of the left subtree and the right subtree
            if |left - right| > 1 => return false. Else, continue
            if you go through all of the tree and haven't returned false yet, return true
        */
    
        if (!root)
        {
            return true;
        }

        return checkBalance(root);
    }

    bool checkBalance(TreeNode* root)
    {
        if (!root)
        {
            return true;
        }

        int heightLeft = height(root->left);
        int heightRight = height(root->right);

        if (std::abs(heightLeft - heightRight) > 1)
        {
            return false;
        }

        // Only accept if the answer is true when propagated over all subtrees
        return checkBalance(root->left) && checkBalance(root->right);
    }

    int height(TreeNode* root) 
    {
        if(!root)
        {
            return -1;
        }

        if(!root->left && !root->right)
        {
            return 0;
        }

        return std::max(height(root->left), height(root->right)) + 1;
    }
   
    
};
