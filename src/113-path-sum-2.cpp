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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        if (!root) {
            return vector<vector<int>>();
        }

        std::stack<std::tuple<TreeNode*, int, vector<int>>> dfsStack; // Holds the node with the sum at that current node
        vector<int> path;
        dfsStack.push(createNode(root,root->val,path));
        vector<vector<int>> result;

        while (!dfsStack.empty()) {
            auto top = dfsStack.top();   
            auto root = std::get<0>(top);
            dfsStack.pop();

            if (!root->left && !root->right) {
                if (std::get<1>(top) == targetSum) {
                    result.push_back(std::get<2>(top));
                }

                continue;
            }

            if (root->left) {
                dfsStack.push(createNode(root->left, std::get<1>(top) + root->left->val, std::get<2>(top)));
            }

            if (root->right) {
                dfsStack.push(createNode(root->right,std::get<1>(top) + root->right->val, std::get<2>(top)));
            }
        
        }

        return result;
    }

    std::tuple<TreeNode*, int, vector<int>> createNode(TreeNode* root, int sum, vector<int> path) {
        std::tuple<TreeNode*, int, vector<int>> node;
        std::get<0>(node) = root;
        std::get<1>(node) = sum;
        path.push_back(root->val);
        std::get<2>(node) = path;

        return node;
    }
};
