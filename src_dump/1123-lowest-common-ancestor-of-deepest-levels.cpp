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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_set<int> bottomLeafValues;
        vector<vector<TreeNode*>> treeLevelMatrix;

        if (!root->left && !root->right) {
            return root;
        }

        queue<pair<int, TreeNode*>> bfs;
        int currLevel = 0;
        bfs.push({currLevel, root});

        vector<TreeNode*> currLevelEntry;

        while (!bfs.empty()) {
            auto entry = bfs.front();
            bfs.pop();

            if (entry.first > currLevel) {
                // we have reached a new level
                treeLevelMatrix.push_back(currLevelEntry);
                currLevelEntry = vector<TreeNode*>();
                currLevel++;
            }

            currLevelEntry.push_back(entry.second);

            if (entry.second->left) {
                bfs.push({currLevel + 1, entry.second->left});
            }

            if (entry.second->right) {
                bfs.push({currLevel + 1, entry.second->right});
            }
        }

        if (!currLevelEntry.empty()) {
            treeLevelMatrix.push_back(currLevelEntry);
        }

        if (treeLevelMatrix[treeLevelMatrix.size() - 1].size() == 1) {
            return treeLevelMatrix[treeLevelMatrix.size() - 1][0];
        }

        // the bottom layer of the matrix are the lowest leaves
        for (int i = 0; i < treeLevelMatrix[treeLevelMatrix.size() - 1].size(); ++i) {
            bottomLeafValues.insert(treeLevelMatrix[treeLevelMatrix.size() - 1][i]->val);
        }

        // Iterate the level matrix starting from size() - 2 and do a dfs

        for (int i = treeLevelMatrix.size() - 2; i >= 0; --i) {
            for (int k = 0; k < treeLevelMatrix[i].size(); ++k) {
                bool res = nodeContainsAllBottomLeaves(bottomLeafValues, treeLevelMatrix[i][k]);

                if (res) {
                    return treeLevelMatrix[i][k];
                }
            }
        }

        return root;
    }

    bool nodeContainsAllBottomLeaves(unordered_set<int> bottomLeafValues, 
        TreeNode* root) {
        stack<TreeNode*> dfs;
        dfs.push(root);

        while (!dfs.empty()) {
            TreeNode* node = dfs.top();
            dfs.pop();

            if (bottomLeafValues.empty()) {
                return true;
            }

            if (bottomLeafValues.find(node->val) != bottomLeafValues.end()) {
                bottomLeafValues.erase(node->val);
            }

            if (node->left) {
                dfs.push(node->left);
            }

            if (node->right) {
                dfs.push(node->right);
            }
        }

        return bottomLeafValues.empty();            
    }
};
