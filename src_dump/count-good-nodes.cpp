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
    int goodNodes(TreeNode* root) {
        
        if (!root)
        {
            return 0;
        }

        int maxValSubtree = INT_MIN;
        int count = 0;

        countGoodNodes(root, maxValSubtree, count);
        return count;
    }

    void countGoodNodes(TreeNode* node, int maxValSubtree, int& count)
    {
        if (node->val >= maxValSubtree) {
            count++;
            maxValSubtree = node->val;
        }


        if (node->left)
        {
            countGoodNodes(node->left, maxValSubtree, count);
        }

        if (node->right)
        {
            countGoodNodes(node->right, maxValSubtree, count);
        }
    }
};
