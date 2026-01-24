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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        std::queue<pair<TreeNode*, int>> bfs;
        bfs.push({root, 0});     
        vector<TreeNode*> nodesToReverse;

        while (!bfs.empty()) {
            auto node = bfs.front();
            bfs.pop();

            if (!node.first) {
                continue;
            }

            if (isOdd(node.second)) {
                nodesToReverse.push_back(node.first);
            }
            else {
                reverseArr(nodesToReverse); 
                nodesToReverse = std::vector<TreeNode*>();
            }

            if (node.first->left) {
                bfs.push({node.first->left, node.second + 1});
            }

            if (node.first->left) {
                bfs.push({node.first->right, node.second + 1});
            }

        }

        if (nodesToReverse.size() > 0) {
            reverseArr(nodesToReverse); 
        }

        return root;

    }

    void reverseArr(vector<TreeNode*>& nodesToReverse) {
        int pointerA = 0;
        int pointerB = nodesToReverse.size() - 1;
        while (pointerA < pointerB) {
            int copy = nodesToReverse[pointerA]->val;
            nodesToReverse[pointerA]->val = nodesToReverse[pointerB]->val;
            nodesToReverse[pointerB]->val = copy;

            pointerA++;
            pointerB--;
        }
    }

    bool isOdd(const int& num) {
        if (num % 2 == 0) {
            return false;
        }

        return true;
    }

    
};
