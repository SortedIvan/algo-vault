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
    bool isCompleteTree(TreeNode* root) {
        if (!root || (!root->left && !root->right)) {return true;}

        // to check if a level (except bottom most) is complete
        // -> 2^(level - 1), where level starts from 1

        int maxDepthSize = 0;
        getMaxDepth(maxDepthSize, 0, root);

        std::cout << maxDepthSize << std::endl;

        int level = 0;
        queue<pair<int, TreeNode*>> bfs;
        bfs.push({level, root});

        vector<int> lastLevelValues;

        while (!bfs.empty()) {
            auto node = bfs.front();
            bfs.pop();
            
            if (node.first > level) {
                level++;
            }

            if (node.first + 1 == maxDepthSize) {
                // next level is end, we need to process it specially
                if (node.second->left) {
                    lastLevelValues.push_back(1);
                }
                else {
                    lastLevelValues.push_back(0);
                }

                if (node.second->right) {
                    lastLevelValues.push_back(1);
                }
                else {
                    lastLevelValues.push_back(0);
                }

                continue;
            }

            // check for completeness since we are not at bottom level yet
            if (!node.second->left || !node.second->right) {
                return false;
            }

            // otherwise, add nodes to bfs
            if (node.second->left) {
                bfs.push({level + 1, node.second->left});
            }

            if (node.second->right) {
                bfs.push({level + 1, node.second->right});
            }
        }

        // process last level and check if its correct
        bool foundNull = false;
        for (int i = 0; i < lastLevelValues.size(); ++i) {
            if (!lastLevelValues[i]) {
                foundNull = true;
            }
            else {
                if (foundNull) {
                    return false;
                }
            }
        }

        return true;
    }

    void getMaxDepth(int& maxDepth, int currPathDepth, TreeNode* node) {
        if (!node) return;

        if (!node->left && !node->right) {
            maxDepth = std::max(maxDepth, currPathDepth);
            return;
        }

        if (node->left) {
            getMaxDepth(maxDepth, currPathDepth + 1, node->left);
        }

        if (node->right) {
            getMaxDepth(maxDepth, currPathDepth + 1, node->right);
        }
    }
};
