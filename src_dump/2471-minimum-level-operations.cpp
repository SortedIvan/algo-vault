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
    int minimumOperations(TreeNode* root) {
        // idea:
        // Collect all nodes into lists for each level
        
        if (!root) {
            return 0;
        }

        queue<pair<TreeNode*, int>> bfs;
        bfs.push({root, 0});
        int currentLevel = 0;
        vector<int> elementLevelList;
        int totalSwaps = 0;

        while (!bfs.empty()) {
            auto node = bfs.front();
            bfs.pop();

            if (node.second != currentLevel) {
                totalSwaps += minSwaps(elementLevelList);
                elementLevelList = vector<int>();
                elementLevelList.push_back(node.first->val);
                currentLevel = node.second;
            }
            else {
                elementLevelList.push_back(node.first->val);
            }

            if (node.first->left) {
                bfs.push({node.first->left, currentLevel + 1});
            }

            if (node.first->right) {
                bfs.push({node.first->right, currentLevel + 1});
            }

        }

        if (elementLevelList.size() > 0) {
            totalSwaps += minSwaps(elementLevelList);
        }

        return totalSwaps;
    }


    int minSwaps(vector<int>& arr)
    {
        int n = arr.size();
        pair<int, int> arrPos[n];
        for (int i = 0; i < n; i++) {
            arrPos[i].first = arr[i];
            arrPos[i].second = i;
        }

        sort(arrPos, arrPos + n);

        vector<bool> vis(n, false);

        // Initialize result
        int ans = 0;

        // Traverse array elements
        for (int i = 0; i < n; i++) {
            if (vis[i] || arrPos[i].second == i)
                continue;
                
            int cycle_size = 0;
            int j = i;
            while (!vis[j]) {
                vis[j] = 1;

                // move to next node
                j = arrPos[j].second;
                cycle_size++;
            }

            // Update answer by adding current cycle.
            if (cycle_size > 0) {
                ans += (cycle_size - 1);
            }
        }

        // Return result
        return ans;
    }

};
