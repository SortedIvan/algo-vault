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
    int getMinimumDifference(TreeNode* root) {
        vector<int> nums;
        preOrder(root, nums);
        int min = std::numeric_limits<int>::max();

        for (int i = 0; i < nums.size() - 1; ++i) {
            
            std::cout << nums[i] << std::endl;

            int diff = nums[i + 1] - nums[i];
            min = std::min(diff, min);
        }
        
        return min;
    }

    void preOrder(TreeNode* root, vector<int>& result) {
        if (!root) {
            return;
        }

        if (root->left) {
            preOrder(root->left, result);
        }

        result.push_back(root->val);

        if (root->right) {
            preOrder(root->right, result);
        }

    }
};
