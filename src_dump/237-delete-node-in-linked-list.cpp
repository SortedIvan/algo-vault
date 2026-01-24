/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        vector<int> result;
        switchValues(node, result);
    }

    void switchValues(ListNode* node, vector<int>& result) {
        if (!node->next->next) {
            node->val = node->next->val;
            node->next = nullptr;
            return;
        }

        node->val = node->next->val;
        switchValues(node->next, result);
    }

};
