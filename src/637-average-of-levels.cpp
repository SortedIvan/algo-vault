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
    vector<double> averageOfLevels(TreeNode* root) {
        
        if (!root) {
            return vector<double>();
        }
        
        return traverseTree(root);
    }

    vector<double> traverseTree(TreeNode* root) {
        vector<vector<int>> numbers;
        queue<pair<TreeNode*, int>> bfs;
        bfs.push({root, 1});

        while (!bfs.empty()) {
            auto top = bfs.front();
            bfs.pop();

            if (top.second > numbers.size()) {
                numbers.push_back(vector<int>());
            }

            numbers[top.second - 1].push_back(top.first->val);

            if (top.first->left) {
                bfs.push({top.first->left, top.second + 1});
            }

            if (top.first->right) {
                bfs.push({top.first->right, top.second + 1});
            }
        }

        vector<double> result;

        for (int i = 0; i < numbers.size(); ++i) {
            double avg = 0;

            for (int k = 0; k < numbers[i].size(); ++k) {
                avg += numbers[i][k];
            }

            avg = avg / numbers[i].size();
            result.push_back(avg);
        }

        return result;
    }
};
