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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        set<int> isChild;
        unordered_map<int, vector<pair<int,int>>> nodeMap;
        unordered_map<int, TreeNode*> treeMap;
    
        for (int i = 0; i < descriptions.size(); ++i) {
            if (nodeMap.find(descriptions[i][0]) != nodeMap.end()) {
                nodeMap[descriptions[i][0]].push_back({descriptions[i][1], descriptions[i][2]});
            } else {
                vector<pair<int,int>> newEntry;
                newEntry.push_back({descriptions[i][1], descriptions[i][2]});
                nodeMap.insert({descriptions[i][0], newEntry});
            }

            vector<pair<int,int>> secondEntry;
            nodeMap.insert({descriptions[i][1], secondEntry});
            isChild.insert(descriptions[i][1]); 
        }

        int rootVal = -1;

        for (auto pair : descriptions) {
            if (isChild.find(pair[0]) == isChild.end()) {
                rootVal = pair[0]; 
            } 
        }

        queue<int> process;
        TreeNode* root = new TreeNode(rootVal);

        for (auto child : nodeMap[rootVal]) {
            
            TreeNode* childPointer = new TreeNode(child.first);

            treeMap.insert({child.first, childPointer});

            if (child.second) {
                root->left = childPointer;
            } else {
                root->right = childPointer;
            }

            process.push(child.first);
        }

        treeMap.insert({rootVal, root});

        while (!process.empty()) {
            int top = process.front();
            process.pop();

            if (nodeMap[top].size() == 0) {
                continue;
            }

            for (int i = 0; i < nodeMap[top].size(); ++i) {
                vector<int> description;
                description.push_back(top);
                description.push_back(nodeMap[top][i].first);
                description.push_back(nodeMap[top][i].second);

                process.push(nodeMap[top][i].first);

                insert(description, root, treeMap);
            }
        }


        return root;
    }

    void insert(vector<int>& description, TreeNode*& root, unordered_map<int, TreeNode*>& treeMap) {
        TreeNode* found = treeMap[description[0]];

        if (!found) {
            return;
        }

        TreeNode* child = new TreeNode(description[1]);

        treeMap.insert({description[1], child});

        if (description[2]) {
            if (found->left) {
                return;
            }
            found->left = child;
        } else {
            
            if (found->right) {
                return;
            }

            found->right = child;
        }
    }
};
