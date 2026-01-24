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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return nullptr;
        }

        queue<pair<TreeNode**, TreeNode*>> bfs;
        bfs.push({&root1, root2});

        while (!bfs.empty()) {      
            auto entry = bfs.front();
            bfs.pop();

            if (!entry.first && !entry.second) {
                continue;
            }

            // here, &entry.first->left is the address of the local ptr entry
            // we need what it points to, so we need to dereference it
            TreeNode* n1 = *entry.first;
            TreeNode* n2 = entry.second;

            if (!n1 && n2) {
                *entry.first = n2;
                continue;
            }
            if (!n1 || !n2) continue;  // skip if one of them is null

            // Both nodes exist
            n1->val += n2->val;

            bfs.push({ &n1->left, n2->left });
            bfs.push({ &n1->right, n2->right });
        }

        return root1;
    }
};
