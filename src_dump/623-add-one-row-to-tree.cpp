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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        unordered_map<TreeNode*, vector<TreeNode*>> nodeMap;
        
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        // 1) Populate the node map
        populateNodeMap(root, nodeMap);

        // 2) Collect all parent nodes at (depth - 1)
        vector<TreeNode*> parentNodes;
        collectParentNodes(root, 1, depth - 1, parentNodes);

        // 3) Finally, re-build the tree using the above two data structures
        rebuildTree(parentNodes, nodeMap, val);

        return root;
    }

    void rebuildTree(vector<TreeNode*>& parentNodes, unordered_map<TreeNode*, vector<TreeNode*>>& nodeMap, int val) {
        for (int i = 0; i < parentNodes.size(); ++i) {
            vector<TreeNode*> children = nodeMap[parentNodes[i]];
            parentNodes[i]->left = new TreeNode(val);
            parentNodes[i]->right = new TreeNode(val);

            if (children[0]) {
                parentNodes[i]->left->left = children[0];
            }

            if (children[1]) {
                parentNodes[i]->right->right = children[1];
            }
        }
    }

    void collectParentNodes(TreeNode* root, int currentDepth, int targetDepth, vector<TreeNode*>& parentNodes) {
        if (currentDepth == targetDepth) {
            parentNodes.push_back(root);
        }
        else {
            if (root->left) {
                collectParentNodes(root->left, currentDepth + 1, targetDepth, parentNodes);
            }

            if (root->right) {
                collectParentNodes(root->right, currentDepth + 1, targetDepth, parentNodes);
            }
        }
    }

    void populateNodeMap(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& nodeMap) {
        if (!root) {
            return;
        }

        vector<TreeNode*> children;
        children.push_back(root->left);
        children.push_back(root->right);
        nodeMap.insert({root, children});
        
        if (root->left) {
            populateNodeMap(root->left, nodeMap);
        }

        if (root->right) {
            populateNodeMap(root->right, nodeMap);
        }
    }
};
