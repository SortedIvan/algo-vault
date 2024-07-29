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
    int sumNumbers(TreeNode* root) {
        vector<string> numbers;
        collectNumbers(root, numbers, "");

        int totalSum = 0;

        for (int i = 0; i < numbers.size(); ++i) {
            totalSum += std::stoi(numbers[i]);
        }

        return totalSum;
    }

    void collectNumbers(TreeNode* root, vector<string>& numbers, string currentNumber) {
        if (!root) {
            return;
        }
        
        currentNumber += (root->val + '0');

        if (!root->left && !root->right) {
            numbers.push_back(currentNumber);
            return;
        }

        if (root->left) {
            collectNumbers(root->left, numbers, currentNumber);
        }

        if (root->right) {
            collectNumbers(root->right, numbers, currentNumber);
        }
    }
};
