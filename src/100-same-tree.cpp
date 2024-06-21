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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pStack;
        stack<TreeNode*> qStack;

        if ((p && !q) || (!p && q)) {
            return false;
        }

        if (p == nullptr && q == nullptr) {
            return true;
        }

        pStack.push(p);
        qStack.push(q);

        while (!pStack.empty() && !qStack.empty()) {
            TreeNode* pNode = pStack.top();
            TreeNode* qNode = qStack.top();

            pStack.pop();
            qStack.pop();

            if (!pNode && !qNode) {
                return true;
            }

            if (pNode->val != qNode->val) {
                return false;
            }

            if ((pNode->left && !qNode->left) || (!pNode->left && qNode->left)) {
                return false;
            }

            if ((!pNode->right && qNode->right) || (qNode->right && !qNode->right)) {
                return false;
            }

            if (pNode->left) {
                pStack.push(pNode->left);
            }

            if (pNode->right) {
                pStack.push(pNode->right);
            }
            
            if (qNode->left) {
                qStack.push(qNode->left);   
            }
            
            if (qNode->right) {
                qStack.push(qNode->right);
            }
        }

        if (pStack.size() != qStack.size()) {
            return false;
        }

        return true;
    }
};
