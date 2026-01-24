/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        if (!root) {
            return false;
        }

        vector<int> arr;   
        collectAllValuesInArr(head, arr);
        
        if (arr.empty()) {
            return true;
        }
        
        int arrSize = arr.size();
        queue<TreeNode*> bfs;
        bfs.push(root);

        while (!bfs.empty()) {
            TreeNode* node = bfs.front();
            bfs.pop();
            bool found = false;

            if (arr[0] == node->val) {
                checkForPath(node, found, 1, arr);
            }

            if (found) {
                return true;
            }

            if (node->left) {
                bfs.push(node->left);
            }

            if (node->right) {
                bfs.push(node->right);
            }

        }
        
        return false;
    }

    void checkForPath(TreeNode* root, bool& found, int pointer, vector<int>& arr) {
        if (found) {
            return;
        }

        if (pointer >= arr.size()) {
            found = true;
            return;
        }

        if (!root) {
            return;
        }

        if (root->left) {
            if (root->left->val == arr[pointer]) {
                checkForPath(root->left, found, pointer + 1, arr);
            }
        }

        if (root->right) {
            if (root->right->val == arr[pointer]) {
                checkForPath(root->right, found, pointer + 1, arr);
            }
        }
    }

    void collectAllValuesInArr(ListNode* head, vector<int>& arr) {
        if (!head) {
            return;
        }

        arr.push_back(head->val);
        collectAllValuesInArr(head->next, arr);
    }
};
