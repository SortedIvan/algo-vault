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
    int averageOfSubtree(TreeNode* root) {
        if (!root) {
            return 0;
        }

        if (!root->left && !root->right) {
            return 1;
        }

        return countNumberOfNodesWithAverageSubtrees(root);
    }

    int countNumberOfNodesWithAverageSubtrees(TreeNode* root) {
        std::stack<TreeNode*> dfs;
        dfs.push(root);
        int counter = 0;

        while (!dfs.empty()) {
            TreeNode* top = dfs.top();
            dfs.pop();
            
            int average = calculateAverageOfSubtree(top);

            if (average == top->val) {
                counter++;
            }

            if (top->left) {
                dfs.push(top->left);
            }

            if (top->right) {
                dfs.push(top->right);
            }
        }

        return counter;
    }

    int calculateAverageOfSubtree(TreeNode* subtreeRoot) {
        std::queue<TreeNode*> bfs;
        bfs.push(subtreeRoot);

        int numberOfNodes = 0;
        int sum = 0;

        while (!bfs.empty()) {
            TreeNode* first = bfs.front();
            bfs.pop();

            numberOfNodes++;
            sum += first->val;

            if (first->left) {
                bfs.push(first->left);
            }

            if (first->right) {
                bfs.push(first->right);
            }
        }

        return std::floor(sum / numberOfNodes);
    }
};
