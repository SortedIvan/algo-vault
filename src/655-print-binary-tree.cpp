struct BfsEntry {
public:
    TreeNode* node;
    int row;
    int column;

    BfsEntry(TreeNode* node, int row, int column) {
        this->node = node;
        this->row = row;
        this->column = column;
    }
};

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
    vector<vector<string>> printTree(TreeNode* root) {
        // idea: first construct the matrix and then do a second pass and populate
        vector<vector<string>> treeMatrix;
        int height = getHeight(root);

        int cols = std::pow(2, (height + 1)) - 1;

        for (int i = 0; i < height + 1; ++i) {
            vector<string> rowEntry;
            for (int k = 0; k < cols; ++k) {
                rowEntry.push_back("");
            }
            treeMatrix.push_back(rowEntry);
        }

        int startRow = 0;
        int startCol = (cols - 1) / 2;

        populateTreeMatrix(startRow, startCol, root, treeMatrix, height);

        return treeMatrix;
    }

    // c-2^(height-r)-1 : left
    // c+2^(height-r)-1 : right
    void populateTreeMatrix(int startRow, int startCol, TreeNode* root, 
                vector<vector<string>>& treeMatrix, int height) 
    {
        queue<BfsEntry> bfs;
        auto firstEntry = BfsEntry(root, startRow, startCol);
        bfs.push(firstEntry);

        while (!bfs.empty()) {
            BfsEntry entry = bfs.front();
            bfs.pop();

            treeMatrix[entry.row][entry.column] = std::to_string(entry.node->val);

            if (entry.node->left) {
                int nextCol = entry.column - std::pow(2, height - entry.row - 1);
                bfs.emplace(BfsEntry(entry.node->left, entry.row + 1, nextCol));
            }

            if (entry.node->right) {
                int nextCol = entry.column + std::pow(2, height - entry.row - 1);
                bfs.emplace(BfsEntry(entry.node->right, entry.row + 1, nextCol));
            }
        }
    }


    int getHeight(TreeNode* node) {
        if (!node) {
            return 0;
        }
        
        stack<pair<TreeNode*, int>> dfs;
        dfs.push({node,0});
        int maxDepth = 0;

        while (!dfs.empty()) {
            auto treeEntry = dfs.top();
            dfs.pop();

            maxDepth = std::max(maxDepth, treeEntry.second);

            if (treeEntry.first->left) {
                dfs.push({treeEntry.first->left, treeEntry.second + 1});
            }

            if (treeEntry.first->right) {
                dfs.push({treeEntry.first->right, treeEntry.second + 1});
            }
        }

        return maxDepth;
    }

};
