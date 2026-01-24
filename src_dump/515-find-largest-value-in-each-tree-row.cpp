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
    vector<int> largestValues(TreeNode* root) {
        if (!root) {
            return vector<int>();
        }
        return getLargestValues(root);
    }

    vector<int> getLargestValues(TreeNode* root) {
        vector<int> result;
        result.push_back(root->val);
        queue<pair<int, TreeNode*>> bfs;
        int currentLevel = 1;
        int currentBiggestNode = root->val;

        if (root->left) {
            currentBiggestNode = root->left->val;
            bfs.push({currentLevel, root->left});
        }

        if (root->right) {
            currentBiggestNode = root->right->val;
            bfs.push({currentLevel, root->right});
        }

        if (!root->left && !root->right) {
            return result;
        }

        while (!bfs.empty()) {
            auto node = bfs.front();
            bfs.pop();
            
            if (node.first > currentLevel) {
                currentLevel++;
                result.push_back(currentBiggestNode);
                currentBiggestNode = node.second->val;
            } else {
                currentBiggestNode = std::max(currentBiggestNode, node.second->val);
            }

            if (node.second->left) {
                bfs.push({currentLevel + 1, node.second->left});
            }
            
            if (node.second->right) {
                bfs.push({currentLevel + 1, node.second->right});
            }
        }

        result.push_back(currentBiggestNode);

        return result;
    }
};
