/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
    
        if (!root) {
            return result;
        }

        performTraversal(result, root);
        return result;
    }

    void performTraversal(vector<vector<int>>& result, Node* root) {
        queue<pair<int, Node*>> bfs;
        int currentLevel = 0;
        bfs.push({currentLevel, root});
        vector<int> currentLevelValues;

        while (!bfs.empty()) {
            auto node = bfs.front();
            bfs.pop();

            // we've started processing the next level
            if (node.first > currentLevel) {
                result.push_back(currentLevelValues);
                currentLevelValues = vector<int>();
                currentLevel++;
            }

            currentLevelValues.push_back(node.second->val);

            for (int i = 0; i < node.second->children.size(); ++i) {
                bfs.push({currentLevel + 1, node.second->children[i]});
            }
        }

        // once we are done, we might have to push the last level
        if (!currentLevelValues.empty()) {
            result.push_back(currentLevelValues);
        }
    }
};
