/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        if (k == 0) {
            vector<int> result = {target->val};
            return result;
        }

        unordered_map<int, vector<int>> adjacencyList;
        createAdjacencyList(root, adjacencyList);
        return findAllNodesOfDistanceK(adjacencyList, target->val, k);
    }

    vector<int> findAllNodesOfDistanceK(unordered_map<int, vector<int>>& adjacencyList, int target, int k) {
        vector<int> result;
        set<int> processed;
        queue<pair<int,int>> bfs;
        bfs.push(std::make_pair(target, 0));

        while (!bfs.empty()) {
            pair<int, int> node = bfs.front();
            bfs.pop();

            processed.insert(node.first);

            if (node.second > k) {
                continue;
            }

            if (node.second != 0 && node.second == k && node.first != target) {
                result.push_back(node.first);
            }

            for (int i = 0; i < adjacencyList[node.first].size(); ++i) {

                if (adjacencyList[node.first][i] == target) {
                    continue;
                }

                if (processed.find(adjacencyList[node.first][i]) != processed.end()) {
                    continue;
                }

                bfs.push({adjacencyList[node.first][i], node.second + 1});
            }
        }

        return result;
    }

    void createAdjacencyList(TreeNode* root, unordered_map<int, vector<int>>& adjacencyList) {
        if (!root) {
            return;
        }

        if (root->left) {
            adjacencyList[root->val].push_back(root->left->val);
            adjacencyList[root->left->val].push_back(root->val);

            createAdjacencyList(root->left, adjacencyList);
        }

        if (root->right) {
            adjacencyList[root->val].push_back(root->right->val);
            adjacencyList[root->right->val].push_back(root->val);
            createAdjacencyList(root->right, adjacencyList);
        }
    }
};
