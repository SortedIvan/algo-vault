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
    int kthSmallest(TreeNode* root, int k) {
        // dummy approach: 
        // traverse the tree in-order: go all the way left and collect the nodes into a list

        std::vector<int> nodes;
        collectAllNodes(root, nodes);

        // nodes is now sorted, traverse it until the kth smallest
        return nodes[k - 1];
    }

    void collectAllNodes(TreeNode* root, std::vector<int>& nodes)
    {
        if (!root)
        {
            return;
        }

        if (root->left)
        {
            collectAllNodes(root->left, nodes);
        }

        nodes.push_back(root->val);

        if (root->right)
        {
            collectAllNodes(root->right, nodes);
        }
    }
};
