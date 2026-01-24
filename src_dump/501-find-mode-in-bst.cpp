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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> occuranceMap;
        populateOccuranceMap(occuranceMap, root);

        int largest = std::numeric_limits<int>::min();
        for (auto node : occuranceMap) {
            if (node.second > largest) {
                largest = node.second;
            }
        }

        vector<int> result;
        for (auto node : occuranceMap) {
            if (node.second == largest) {
                result.push_back(node.first);
            }
        }

        return result;
    }

    void populateOccuranceMap(unordered_map<int,int>& occuranceMap, TreeNode* root) {
        if (!root) {
            return;
        }

        occuranceMap[root->val]++;
        if (root->left) {
            populateOccuranceMap(occuranceMap, root->left);
        }

        if (root->right) {
            populateOccuranceMap(occuranceMap, root->right);
        }
    }
};
