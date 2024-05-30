/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (!root)
        {
            return nullptr;
        }   

        return findLca(root, p, q);
    }

    TreeNode* findLca(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root->val > p->val && root->val > q->val)
        {
            if (root->left)
            {
                return findLca(root->left, p, q);
            }
        }
        
        if (root->val < p->val && root->val < q->val)
        {
            if (root->right)
            {
                return findLca(root->right, p, q);
            }
        }
        
        return root;
    }


};
