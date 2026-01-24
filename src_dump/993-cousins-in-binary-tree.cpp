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
    bool isCousins(TreeNode* root, int x, int y) {
        // cousins: same depth but different parents

        if (!root) {
            return false;
        }

        return getCousins(root, x, y);
    }

    bool getCousins(TreeNode* root, int x, int y) {
        int cousDepth1 = -1;
        int cousDepth2 = -1;

        int cousParent1 = -1;
        int cousParent2 = -1;

        queue<pair<TreeNode*, int>> bfs;
        bfs.push({root, 0});

        if (root->val == x) {
            cousDepth1 = 0;
        } else if (root->val == y) {
            cousDepth2 = 0;
        }

        while (!bfs.empty()) {
            if (cousDepth1 != -1 && cousDepth2 != -1) {
                break;
            }

            auto top = bfs.front();
            bfs.pop();

            if (top.first->left) {
                if (top.first->left->val == x) {
                    cousParent1 = top.first->val;
                    cousDepth1 = top.second + 1;
                } else if (top.first->left->val == y) {
                    cousParent2 = top.first->val;
                    cousDepth2 = top.second + 1;
                }

                bfs.push({top.first->left, top.second + 1});
            }

            if (top.first->right) {
                if (top.first->right->val == x) {
                    cousDepth1 = top.second + 1;
                    cousParent1 = top.first->val;
                } else if (top.first->right->val == y) {
                    cousDepth2 = top.second + 1;
                    cousParent2 = top.first->val;
                }

                bfs.push({top.first->right, top.second + 1});
            }
        }


        if (cousDepth1 != cousDepth2) {
            return false;
        }

        if (cousParent1 == cousParent2) {
            return false;
        }

        return true;
    }

    
};
