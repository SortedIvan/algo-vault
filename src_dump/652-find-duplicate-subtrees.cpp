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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> subtrees;
        queue<TreeNode*> bfs;
        vector<TreeNode*> result;
        bfs.push(root);

        while (!bfs.empty()) {
            TreeNode* top = bfs.front();
            bfs.pop();
            
            if (!top) {
                continue;
            }

            string hash;
            string type = "r";
            createHash(hash,top,type);

            if (hash.size() > 0) {
                subtrees[hash].push_back(top);
            }

            if (top->left) {
                bfs.push(top->left);
            }

            if (top->right) {
                bfs.push(top->right);
            }
        }

        for (auto pair : subtrees) {
            if (pair.second.size() > 1) {
                result.push_back(pair.second[0]);
            }
        }

        return result;
    }
    void createHash(string& result, TreeNode* root, string type) {
            if (!root) {
                return;
            }

            result += std::to_string(root->val);
            result += type;


            if (root->left){
                createHash(result, root->left, "le");
            }
            else {
                result += "LN";
            }

            if (root->right) {
                createHash(result, root->right, "ri");
            }
            else {
                result += "RN";
            }
    }
    
};
