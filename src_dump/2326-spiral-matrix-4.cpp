/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix;
        vector<vector<int>> seen;
        for (int i = 0; i < m; i++) {
            vector<int> row;
            vector<int> seenRow;
            for (int k = 0; k < n; ++k) {
                row.push_back(-1);
                seenRow.push_back(0);
            }
            seen.push_back(seenRow);
            matrix.push_back(row);
        }

        if (!head) {
            return matrix;
        }

        matrix[0][0] = head->val;
        seen[0][0] = 1;
        pair<int, int> currDirection = {0,1};
        populateMatrix(matrix, 0, 0, seen, currDirection, head->next);
        return matrix;
    }

    void populateMatrix(vector<vector<int>>& matrix,int x, int y, vector<vector<int>>& seen,pair<int,int>& currDirection, ListNode* head) {
        if (!head) {
            return;
        }
        
        int newX = x + currDirection.first;
        int newY = y + currDirection.second;

        if (newX < 0 || newY < 0 || newX >= matrix.size() || newY >= matrix[0].size()) {
            switchDirection(currDirection);
            populateMatrix(matrix, x, y, seen, currDirection, head);
            return;
        }

        if (seen[newX][newY]) {
            switchDirection(currDirection);
            populateMatrix(matrix, x, y, seen, currDirection, head);
            return;
        }

        seen[newX][newY] = 1;
        matrix[newX][newY] = head->val;
        populateMatrix(matrix, newX, newY, seen, currDirection, head->next);
    } 

    void switchDirection(pair<int,int>& currDirection) {
        if (currDirection.first == 0 && currDirection.second == 1) {
            currDirection = {1, 0}; 
        } else if (currDirection.first == 1 && currDirection.second == 0) { 
            currDirection = {0, -1};
        } else if (currDirection.first == 0 && currDirection.second == -1) {
            currDirection = {-1, 0}; 
        } else { 
            currDirection = {0, 1};
        }
    }
};
