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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        stack<vector<int>> resultStack; 
        vector<vector<int>> result;

        if (!root) {
            return result;
        }

        queue<pair<int, TreeNode*>> bfs;
        bfs.push({0, root});
        int currLevel = 0;

        vector<int> currLevelValues;
        
        while (!bfs.empty()) {
            auto node = bfs.front();
            bfs.pop();

            if (node.first > currLevel) {
                resultStack.push(currLevelValues);
                currLevelValues = vector<int>();
                currLevel++;
            }  

            currLevelValues.push_back(node.second->val);

            if (node.second->left) {
                bfs.push({currLevel + 1, node.second->left});
            }

            if (node.second->right) {
                bfs.push({currLevel + 1, node.second->right});
            }
        }

        if (!currLevelValues.empty()) {
            resultStack.push(currLevelValues);
        }

        while (!resultStack.empty()) {
            result.push_back(resultStack.top());
            resultStack.pop();
        }

        return result;
    }
};
