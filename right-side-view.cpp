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
    vector<int> rightSideView(TreeNode* root) {
        // idea:
        // iterate through the entire tree and save the level and save the rightmost node at that level
        // This can be done by just overwriting any nodes that were already there at that level
        
        std::map<int, TreeNode*> levelMap;
        std::vector<int> result; 
        int levelCounter = 0;

        populateLevelMap(root, levelMap, levelCounter);

        map<int, TreeNode*>::iterator it;

        for (it = levelMap.begin(); it != levelMap.end(); it++)
        {
            result.push_back(it->second->val); 
        }

        return result;

    }

    void populateLevelMap(TreeNode* root, std::map<int, TreeNode*>& levelMap, int levelCounter) 
    {
        if (!root)
        {
            return;
        }

        if (levelMap.find(levelCounter) == levelMap.end())
        {
            // has not been found yet, add it
            levelMap.insert({levelCounter, root});
        }
        else
        {
            levelMap[levelCounter] = root;
        }

        if (root->left || root->right)
        {
            levelCounter++;
        }

        if (root->left)
        {
            populateLevelMap(root->left, levelMap, levelCounter);
        }

        if (root->right)
        {
            populateLevelMap(root->right, levelMap, levelCounter);
        }
    }
};
