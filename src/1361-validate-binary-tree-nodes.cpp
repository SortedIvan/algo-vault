class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, pair<int, int>> nodeMap;
        unordered_set<int> hasParentAlready;

        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                if (hasParentAlready.find(leftChild[i]) != hasParentAlready.end()) {
                    return false;
                }

                hasParentAlready.insert(leftChild[i]);
            }

            if (rightChild[i] != -1) {
                if (hasParentAlready.find(rightChild[i]) != hasParentAlready.end()) {
                    return false;
                }

                hasParentAlready.insert(rightChild[i]);
            }

            nodeMap.insert({i, {leftChild[i], rightChild[i]}});
        }

        int root = 0;

        for (int i = 0; i < n; ++i) {
            if (hasParentAlready.find(i) == hasParentAlready.end()) {
                root = i;
                break;
            }
        }

        queue<int> bfs;
        unordered_set<int> seen;
        bfs.push(root);

        while (!bfs.empty()) {
            int top = bfs.front();
            bfs.pop();

            if (seen.find(top) != seen.end()) {
                return false;
            }

            seen.insert(top);

            auto children = nodeMap[top];

            if (children.first != -1) {
                bfs.push(children.first);
            }

            if (children.second != -1) {
                bfs.push(children.second);
            }
        }

        if (seen.size() != leftChild.size()) {
            return false;
        }

        return true;
    }
};
