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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> sumCounter;  
        unordered_map<int, vector<int>> sumsOrdered; 
        populateSums(sumCounter, root);
        int mostFrequent = 0;

        for (auto entry : sumCounter) {
            if (entry.second > mostFrequent) {
                mostFrequent = entry.second;
            }

            sumsOrdered[entry.second].push_back(entry.first);
        } 

        return sumsOrdered[mostFrequent];
    }

    int populateSums(unordered_map<int, int>& sums, TreeNode* root) {
        int sum = 0;

        if (!root) {
            return sum;
        }

        int leftSum = 0;
        int rightSum = 0;

        if (root->left) {
            leftSum = populateSums(sums, root->left);            
        }

        if (root->right) {
            rightSum = populateSums(sums, root->right);
        }
        
        sum = leftSum + rightSum + root->val;
        sums[sum]++;
        return sum;
    }


};
