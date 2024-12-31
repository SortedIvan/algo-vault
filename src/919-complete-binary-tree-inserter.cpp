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
class CBTInserter {
private:
    TreeNode* root;
    
    int insertHelper(int value, TreeNode* root) {
        queue<TreeNode*> bfs;
        bfs.push(root);

        while (!bfs.empty()) {
            TreeNode* node = bfs.front();
            bfs.pop();

            if (node->left) {
                bfs.push(node->left);
            }
            else {
                node->left = new TreeNode(value);
                return node->val;
            }
            
            if (node->right) {
                bfs.push(node->right);
            }
            else {
                node->right = new TreeNode(value);
                return node->val;
            }

        }

        return -1;
    }

public:
    CBTInserter(TreeNode* root) {
        this->root = root;
    }
    
    int insert(int val) {
        return insertHelper(val, root);
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
