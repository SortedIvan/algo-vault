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
    int maxLevelSum(TreeNode* root) {
        if (!root) {
            return -1;
        }

        if (!root->left && !root->right) {
            return 1;
        }

        int currentLevel = 1;
        int currentLevelSum = 0;

        int levelWithMaximalSum = 1;
        int maxSum = std::numeric_limits<int>::min();
        
        std::queue<std::pair<int, TreeNode*>> bfs;
        bfs.push({currentLevel, root});

        while (!bfs.empty()) {
            const auto entry = bfs.front();
            bfs.pop();

            if (entry.first > currentLevel) {
                // We've moved onto a different level
                // Process the sum so far
                if (currentLevelSum > maxSum) {
                    maxSum = currentLevelSum;
                    levelWithMaximalSum = currentLevel;
                }

                currentLevelSum = 0;
                currentLevel = entry.first;
            }

            currentLevelSum += entry.second->val;

            if (entry.second->left) {
                bfs.push({entry.first + 1, entry.second->left});
            }

            if (entry.second->right) {
                bfs.push({entry.first + 1, entry.second->right});
            }
        }

        if (currentLevelSum > maxSum) {
            maxSum = currentLevelSum;
            levelWithMaximalSum = currentLevel;
        }

        return levelWithMaximalSum;
    }
};
