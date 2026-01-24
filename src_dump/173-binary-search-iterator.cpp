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
class BSTIterator {
private:
    TreeNode* root;
    vector<int> result;
    int pointer = 0;
public:
    BSTIterator(TreeNode* root) {
        this->root = root;
        preOrderTraversal(root);
    }
    
    void preOrderTraversal(TreeNode* root) {
        if (!root) {
            return;
        }

        // left -> root -> right

        if (root->left) {
            preOrderTraversal(root->left);
        }

        result.push_back(root->val);

        if (root->right) {
            preOrderTraversal(root->right);
        }
    }

    int next() {
        int next = result[pointer];
        pointer++;
        return next;
    }
    
    bool hasNext() {
        if (pointer >= result.size()) {
            return false;
        }
           
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
