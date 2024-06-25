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
    TreeNode* bstToGst(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        if (!root->left && !root->right) {
            return root;
        }

        TreeNode* result = new TreeNode();
        result->val = root->val;

        copyTree(result, root);
        swapValuesOfNodes(root, result);

        std::cout << findNumbersBiggerThanNode(5, root);

        return result;

    }

    void swapValuesOfNodes(TreeNode* root, TreeNode*& resRoot) {
        stack<TreeNode*> dfs;
        dfs.push(resRoot);

        while (!dfs.empty()) {
            auto process = dfs.top();
            dfs.pop();

            int sum = findNumbersBiggerThanNode(process->val, root);
            process->val = process->val + sum;

            if (process->left) {
                dfs.push(process->left);
            }

            if (process->right) {
                dfs.push(process->right);
            }
        }
    }

    void copyTree(TreeNode*& resRoot, TreeNode* root) {

        if (!root) {
            resRoot = nullptr;
            return;
        }

        resRoot = new TreeNode();
        resRoot->val = root->val;

        if (root->left) {
            copyTree(resRoot->left, root->left);
        }

        if (root->right) {
            copyTree(resRoot->right, root->right);
        }
    }

    int findNumbersBiggerThanNode(int nodeVal, TreeNode* root) {
        queue<TreeNode*> bfs;
        bfs.push(root);
        int sum = 0;

        while (!bfs.empty()) {
            auto front = bfs.front();
            bfs.pop();

            if (front->val > nodeVal) {
                sum += front->val;
            }

            if (front->left) {
                bfs.push(front->left);
            }

            if (front->right) {
                bfs.push(front->right);
            }
        }

        return sum;
    }
};
