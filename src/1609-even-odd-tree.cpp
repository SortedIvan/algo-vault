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

enum Condition {
    Even,
    Odd
};

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (!root) {
            return true;
        }
        
        std::queue<pair<int, TreeNode*>> bfs;
        int level = 0;
        bfs.push({level, root});
        vector<int> currLevelValues;

        while (!bfs.empty()) {
            auto node = bfs.front();
            bfs.pop();
            
            if (node.first > level) {
                // process currLevelValues
                bool result = false;

                if (level % 2 == 0) {
                    result = checkIfConditionsSatisfied(Even, currLevelValues);
                }
                else {
                    result = checkIfConditionsSatisfied(Odd, currLevelValues);
                }

                if (!result) {
                    return false;
                }

                currLevelValues = vector<int>();
                currLevelValues.push_back(node.second->val);

                level = node.first;
            }
            else {
                currLevelValues.push_back(node.second->val);
            }

            if (node.second->left) {
                bfs.push({level + 1, node.second->left});
            }

            if (node.second->right) {
                bfs.push({level + 1, node.second->right});
            }
        }

        if (!currLevelValues.empty()) {
            bool result = false;
            if (level % 2 == 0) {
                result = checkIfConditionsSatisfied(Even, currLevelValues);
            }
            else {
                result = checkIfConditionsSatisfied(Odd, currLevelValues);
            }

            if (!result) {
                return false;
            }
        }

        return true;
    }

    bool checkIfConditionsSatisfied(Condition condition, vector<int>& values) {
        if (values.empty()) {return true;}
        int lastValue = values[0];

        for (int i = 0; i < values.size(); ++i) {
            if (condition == Even) {
                if (values[i] % 2 == 0) {
                    return false;
                }

                if (i == 0) {
                    continue;
                }

                if (lastValue >= values[i]) {
                    return false;
                }
            }
            else {
                if (values[i] % 2 != 0) {
                    return false;
                }

                if (i == 0) {
                    continue;
                }

                if (lastValue <= values[i]) {
                    return false;
                }
            }

            lastValue = values[i];
        }

        return true;
    }

    
};
