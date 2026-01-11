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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        if (!root->left && !root->right) {
            return root;
        }

        int maxDepth = 0;
        getMaxDepth(root, 0, maxDepth);

        int numberOfDeepestNodes = countNumberOfDeepestNodes(root, 0, maxDepth);

        if (numberOfDeepestNodes == 1) {
            return getDeepestNode(root, maxDepth);
        }

        std::stack<pair<int, TreeNode*>> outerDfs;
        outerDfs.push({0, root});

        int maxNodeDepthThatContainsAllDeepestNodes = 0;
        TreeNode* nodeResult = root;

        while (!outerDfs.empty()) {
            auto nodeDepthPair = outerDfs.top();
            outerDfs.pop();

            if (nodeDepthPair.first == maxDepth) {
                continue;
            }

            int leftDeepNodeCount = countNumberOfDeepestNodes(nodeDepthPair.second->left, 
                                                            nodeDepthPair.first + 1, maxDepth);

            int rightDeepNodeCount = countNumberOfDeepestNodes(nodeDepthPair.second->right, 
                                                            nodeDepthPair.first + 1, maxDepth);

            if (leftDeepNodeCount + rightDeepNodeCount == numberOfDeepestNodes) {

                if (nodeDepthPair.first > maxNodeDepthThatContainsAllDeepestNodes) {
                    maxNodeDepthThatContainsAllDeepestNodes = nodeDepthPair.first;    
                    nodeResult = nodeDepthPair.second;
                }
            }

            if (nodeDepthPair.second->left) {
                outerDfs.push({nodeDepthPair.first + 1, nodeDepthPair.second->left});
            }

            if (nodeDepthPair.second->right) {
                outerDfs.push({nodeDepthPair.first + 1, nodeDepthPair.second->right});
            }
        }

        return nodeResult;
    }

    TreeNode* getDeepestNode(TreeNode* root, int maxDepth) {
        if (!root) {
            return nullptr;
        }

        std::stack<std::pair<TreeNode*, int>> dfs;
        dfs.push({root, 0});

        while (!dfs.empty()) {
            auto next = dfs.top();
            dfs.pop();

            if (next.second == maxDepth) {
                return next.first;
            }

            if (next.first->left) {
                dfs.push({next.first->left, next.second + 1});
            }

            if (next.first->right) {
                dfs.push({next.first->right, next.second + 1});
            }
        }

        return nullptr;
    }

    int countNumberOfDeepestNodes(TreeNode* root, int currentDepth, int maxDepth) {
        if (!root) {
            return 0;
        }

        if (currentDepth == maxDepth) {
            return 1;
        }

        return countNumberOfDeepestNodes(root->left, currentDepth + 1, maxDepth)
            + countNumberOfDeepestNodes(root->right, currentDepth + 1, maxDepth);
    }

    void getMaxDepth(TreeNode* root, int currentDepth, int& maxDepth) {
        if (!root) {
            maxDepth = std::max(currentDepth, maxDepth);
            return;
        }

        if (root->left) {
            getMaxDepth(root->left, currentDepth + 1, maxDepth);
        }

        if (root->right) {
            getMaxDepth(root->right, currentDepth + 1, maxDepth);
        }

        maxDepth = std::max(currentDepth, maxDepth);
    }
};
