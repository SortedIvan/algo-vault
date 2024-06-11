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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ordering;

        int level = 0;

        insertNodesPerLevel(ordering, level, root);

        return ordering;
    }

    void insertNodesPerLevel(std::vector<std::vector<int>>& ordering, int level, TreeNode* root)
    {
        if (!root)
        {
            return;
        }

        if (ordering.size() <= level)
        {
            ordering.push_back(std::vector<int>());
        }

        ordering[level].push_back(root->val);

        if (root->left || root->right)
        {
            level++;
        }

        if (root->left)
        {
            insertNodesPerLevel(ordering, level, root->left);
        }

        if (root->right)
        {
            insertNodesPerLevel(ordering, level, root->right);
        }
    }
};

// ------------------------- ALTERNATIVE ------------------------------------
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if (!root)
        {
            return result;
        }

        result.push_back(vector<int>());

        queue<pair<TreeNode*, int>> bfs;
        int level = 0;
        bfs.push(std::make_pair(root, level));

        while (!bfs.empty()) {
            pair<TreeNode*, int> toProcess = bfs.front();
            bfs.pop();

            if (toProcess.second != level) {
                // we have traversed a new level
                result.push_back(vector<int>());
                level = toProcess.second;
            }

            result[level].push_back(toProcess.first->val);

            if (toProcess.first->left) {
                bfs.push(std::make_pair(toProcess.first->left, toProcess.second + 1));
            }

            if (toProcess.first->right) {
                bfs.push(std::make_pair(toProcess.first->right, toProcess.second + 1));
            }

        }

        return result;
    }
};
