/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    vector<vector<int>> globalGrid;

    Node* construct(vector<vector<int>>& grid) {
        globalGrid = grid;
        return dfsConstruct(0, 0, grid.size());
    }

    bool shouldSplit(int x, int y, int size) {
        int value = globalGrid[x][y];
        for (int i = x; i < x + size; ++i) {
            for (int j = y; j < y + size; ++j) {
                if (globalGrid[i][j] != value) {
                    return true;
                }
            }
        }
        return false;
    }

    Node* dfsConstruct(int x, int y, int size) {
        if (size == 1) {
            return new Node(globalGrid[x][y], true);
        }

        if (!shouldSplit(x, y, size)) {
            return new Node(globalGrid[x][y], true);
        }

        int half = size / 2;
        return new Node(
            false, 
            false, 
            dfsConstruct(x, y, half), 
            dfsConstruct(x, y + half, half),
            dfsConstruct(x + half, y, half),
            dfsConstruct(x + half, y + half, half)
        );
    }
};
