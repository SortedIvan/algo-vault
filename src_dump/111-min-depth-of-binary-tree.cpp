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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        if (!root->left && !root->right) {
            return 1;
        }

        int minDepth = std::numeric_limits<int>::max();
        findMinDepth(minDepth, root, 0);
        return minDepth + 1;
    }

    void findMinDepth(int& min, TreeNode* root, int currDepth) {
        if (!root) {
            return;
        }

        if (!root->left && !root->right) {
            min = std::min(currDepth, min);
        }
        else {
            if (root->left) {
                if (currDepth >= min) {
                    return;
                }
                findMinDepth(min, root->left, currDepth + 1);
            }

            if (root->right) {
                if (currDepth >= min) {
                    return;
                }
                findMinDepth(min, root->right, currDepth + 1);
            }
        }
    }
};
