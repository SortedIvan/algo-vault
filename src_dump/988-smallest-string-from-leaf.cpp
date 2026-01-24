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
    string smallestFromLeaf(TreeNode* root) {
        map<string, int> words;
        collectAllWords(root, words, "");
        return words.begin()->first;
    }

    // a word is from root to leaf
    void collectAllWords(TreeNode* root, map<string, int>& words, std::string currentWord) {
        if (!root) {
            return;
        }

        char character = char(root->val + 'a');
        currentWord = character + currentWord;

        if (!root->left && !root->right) {
            words.insert({currentWord, 1});
        }
        else {
            if (root->left) {
                collectAllWords(root->left, words, currentWord);
            }

            if (root->right) {
                collectAllWords(root->right, words, currentWord);
            }
        }
    }

};
