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
    // Idea 1: Go over the levels, collect the sums in pq and then do while not k 
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) {
            return 0;
        }

        priority_queue<long long> levelSums;
        queue<pair<int, TreeNode*>> bfs; // {level, node}
        bfs.push({0, root});
        int currentLevel = 0;
        long long currentSum = 0;

        while (!bfs.empty()) {
            auto node = bfs.front();
            bfs.pop();

            if (currentLevel < node.first) {
                currentLevel++;
                levelSums.push(currentSum);
                currentSum = 0;
            }

            currentSum += node.second->val;

            if (node.second->left) {
                bfs.push({currentLevel + 1, node.second->left});
            }

            if (node.second->right) {
                bfs.push({currentLevel + 1, node.second->right});
            }

        }

        if (currentSum != 0) {
            levelSums.push(currentSum);
        }

        int counter = 1;
        while (!levelSums.empty()) {
            long long sum = levelSums.top();
            levelSums.pop();
            
            if (counter == k) {
                return sum;
            }

            counter++;
        }

        return -1;
    }

};
