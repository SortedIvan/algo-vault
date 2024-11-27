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
    int minDiffInBST(TreeNode* root) {
        vector<int> array;
        inOrderTraversal(array, root);

        if (array.size() == 0) {
            return 0;
        }

        if (array.size() == 1) {
            return array[0];
        }

        if (array.size() == 2) {
            return std::abs(array[0] - array[1]);
        }

        int minDistance = std::numeric_limits<int>::max();

        for (int i = 0; i < array.size(); ++i) {
            if (i == 0) {
                minDistance = std::min(std::abs(array[0] - array[1]), minDistance);
            } else if (i == array.size() - 1) {
                minDistance = std::min(std::abs(array[array.size() - 1] - array[array.size() - 2]), minDistance);
            } else {
                minDistance = std::min(std::abs(array[i] - array[i - 1]), minDistance);
                minDistance = std::min(std::abs(array[i] - array[i + 1]), minDistance);
            }
        }

        return minDistance;
    }

    void inOrderTraversal(vector<int>& array, TreeNode* root) {
        if (!root) {
            return;
        }

        if (root->left) {
            inOrderTraversal(array, root->left);
        }

        array.push_back(root->val);

        if (root->right) {
            inOrderTraversal(array, root->right);
        }
    }
};
