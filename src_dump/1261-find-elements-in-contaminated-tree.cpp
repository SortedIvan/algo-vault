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
class FindElements {
private:
    std::unordered_set<int> exists;
    void fixContaminatedTree(TreeNode* root) {
        if (!root) {
            return;
        }

        if (root->left) {
            int fixedValue = (2 * root->val) + 1;
            root->left->val = fixedValue;
            exists.insert(fixedValue);
            fixContaminatedTree(root->left);
        }  

        if (root->right) {
            int fixedValue = (2 * root->val) + 2;
            root->right->val = fixedValue;
            exists.insert(fixedValue);
            fixContaminatedTree(root->right);
        }    
    }

public:
    FindElements(TreeNode* root) {
        if (!root) {
            return;
        }
        exists.insert(0);
        root->val = 0;
        fixContaminatedTree(root);
    }

    bool find(int target) {
        return exists.find(target) != exists.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
