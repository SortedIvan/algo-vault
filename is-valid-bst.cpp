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
    bool isValidBST(TreeNode* root) {

        if (!root)
        {
            return true;
        }

        stack<TreeNode*> dfsStack;
        dfsStack.push(root);

        while (!dfsStack.empty())
        {
            TreeNode* toProcess = dfsStack.top();

            dfsStack.pop();

            bool validation = validate(toProcess->left, false, toProcess->val) 
                           && validate(toProcess->right, true, toProcess->val);

            if (!validation)
            {
                return false;
            }

            if (toProcess->left)
            {
                dfsStack.push(toProcess->left);
            }

            if (toProcess->right)
            {
                dfsStack.push(toProcess->right);
            }
            
        }

        return true;
    }

    

    // @param direction: false for left, true for right
    bool validate(TreeNode* root, bool direction, int origRootVal) 
    {
        if (!root)
        {
            return true;
        }

        if (!direction)
        {
            // we are somewhere in the left subtree
            if (root->val >= origRootVal)
            {
                return false;
            }
        }
        else
        {
            if (root->val <= origRootVal)
            {
                return false;
            }
        }

        if (root->left && root->val <= root->left->val)
        {
            return false;
        }

        if (root->right && root->val >= root->right->val)
        {
            return false;
        }

        return validate(root->left, direction, origRootVal) && validate(root->right, direction, origRootVal);
    }
};
