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
    int maxDepth(TreeNode* root) 
    {
        if (!root)
        {
            return 0;
        }


        stack<pair<TreeNode*, int>> dfsStack;
        root->val = 999;
        dfsStack.push({root, 1});

        int maxDepth = 1;

        dfs(dfsStack, root, maxDepth, 1);

        return maxDepth;
    }

    void dfs(stack<pair<TreeNode*, int>>& dfsStack, TreeNode* curr, int& maxDepth, int currDepth)
    {
        bool exist = false;
        
        if (curr->left)
        {
            if (curr->left->val != 999)
            {
                curr->left->val = 999;
                dfsStack.push({curr->left,currDepth + 1});
                dfs(dfsStack, curr->left,maxDepth, currDepth + 1);
                exist = true;
            }
        }

        if (curr->right)
        {
            if (curr->right->val != 999)
            {
                curr->right->val = 999;
                dfsStack.push({curr->right, currDepth + 1});
                dfs(dfsStack, curr->right,maxDepth,currDepth + 1);
                exist = true;
            }
        }

        if (!exist)
        {

            if (currDepth > maxDepth)
            {
                maxDepth = currDepth;
            }

            dfsStack.pop();

            if (dfsStack.empty())
            {
                return;
            }

            dfs(dfsStack, dfsStack.top().first, maxDepth, dfsStack.top().second);
        }
    }
};
