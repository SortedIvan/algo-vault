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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return findIfSubtree(root, subRoot);
    }

    bool findIfSubtree(TreeNode* mainTree, TreeNode* toCheck) {
        std::stack<TreeNode*> toProcess;
        toProcess.push(mainTree);

        while (!toProcess.empty()) {
            TreeNode* curr = toProcess.top();
            toProcess.pop();

            if (!curr) {
                continue;
            }

            if (curr->val == toCheck->val) {
                if (subtreeChecker(curr, toCheck)) {
                    return true;
                }
            }

            if (curr->left) {
                toProcess.push(curr->left);
            }

            if (curr->right) {
                toProcess.push(curr->right);
            }
        }

        return false;
    }

    bool subtreeChecker(TreeNode* mainTree, TreeNode* toCheck) {
        if (mainTree->val != toCheck->val) {
            return false;
        }

        bool leftSame = false;
        bool rightSame = false;

        if (mainTree->left && toCheck->left) {
            leftSame = subtreeChecker(mainTree->left, toCheck->left);
        }
        else if (!mainTree->left && !toCheck->left) {
            leftSame = true;
        }
        else {
            leftSame = false;
        }

        if (mainTree->right && toCheck->right) {
            rightSame = subtreeChecker(mainTree->right, toCheck->right);
        }
        else if (!mainTree->right && !toCheck->right) {
            rightSame = true;
        }
        else {
            rightSame = false;
        }

        return rightSame && leftSame;
    }
};
