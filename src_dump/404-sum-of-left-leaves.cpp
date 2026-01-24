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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        if (!root->left && !root->right) {
            return 0;
        }

        int sum = 0;
        sumLeftLeaves(sum, false, root);
        return sum;
    }

    void sumLeftLeaves(int& sum, bool isLeft, TreeNode* root) {
        if (!root) {
            return;
        }

        if (!root->left && !root->right) {
            if (isLeft) {
                sum += root->val;
            }
        } else {
            if (root->left) {
                sumLeftLeaves(sum, true, root->left);
            } 

            if (root->right) {
                sumLeftLeaves(sum, false, root->right);
            }
        }
    }


};
