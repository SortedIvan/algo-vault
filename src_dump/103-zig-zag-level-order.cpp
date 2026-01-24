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
class Solution 
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;

        if (!root) 
        {
            return result;
        }

        bool direction = false;
        queue<TreeNode*> bfs; 
        bfs.push(root);
        
        while (!bfs.empty()) 
        {
            int level = bfs.size();

            direction = !direction;

            vector<int> row;
            deque<int> dq; 

            for (int i = 0; i < level; i++) 
            {
                TreeNode* toProcess = bfs.front();
                bfs.pop();

                if (!direction)
                {
                    dq.push_front(toProcess->val);
                }
                else
                {
                    dq.push_back(toProcess->val);
                }

                if (toProcess->left)
                {
                    bfs.push(toProcess->left);
                }

                if (toProcess->right)
                {
                    bfs.push(toProcess->right);
                }
            }

            while (!dq.empty())
            {
                row.push_back(dq.front());
                dq.pop_front();
            }

            result.push_back(row);

        }

        return result;

    }
};
