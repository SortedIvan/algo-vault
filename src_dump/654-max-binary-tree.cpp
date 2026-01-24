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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }

        if (nums.size() == 1) {
            return new TreeNode(nums[0]);
        }

        int firstBiggestNumberIndex = findIndexOfMaxNumber(nums);
        TreeNode* root = new TreeNode(nums[firstBiggestNumberIndex]);
        auto prefixAndSuffixArrays = constructPrefixAndSuffixArrays(nums, firstBiggestNumberIndex);

        constructHelper(prefixAndSuffixArrays.first, root->left);
        constructHelper(prefixAndSuffixArrays.second, root->right);

        return root;
    }

    void constructHelper(vector<int> nums, TreeNode*& root) {
        if (nums.empty()) {
            root = nullptr;
            return;
        }
        
        int biggestIndex = findIndexOfMaxNumber(nums);
        auto prefixAndSuffixArrays = constructPrefixAndSuffixArrays(nums, biggestIndex);
        root = new TreeNode(nums[biggestIndex]);

        constructHelper(prefixAndSuffixArrays.first, root->left);
        constructHelper(prefixAndSuffixArrays.second, root->right);
    }

    std::pair<vector<int>, vector<int>> constructPrefixAndSuffixArrays(vector<int>& nums, int maxNumberIndex) {
        vector<int> prefix;
        vector<int> suffix;

        if (maxNumberIndex == 0) {
            prefix = std::vector<int>();
            
            for (int i = maxNumberIndex + 1; i < nums.size(); ++i) {
                suffix.push_back(nums[i]);
            }
        }
        else if (maxNumberIndex == nums.size() - 1) {
            suffix = std::vector<int>();
            for (int i = 0; i < maxNumberIndex; ++i) {
                prefix.push_back(nums[i]);
            }
        }
        else {
            for (int i = maxNumberIndex + 1; i < nums.size(); ++i) {
                suffix.push_back(nums[i]);
            }
            for (int i = 0; i < maxNumberIndex; ++i) {
                prefix.push_back(nums[i]);
            }
        }

        return std::make_pair(prefix, suffix);
    }

    int findIndexOfMaxNumber(vector<int>& arr) {
        int max = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] > arr[max]) {
                max = i;
            }
        }
        return max;
    }
};
