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
    ListNode* swapPairs(ListNode* head) {
        traverseAndSwap(head);
        return head;
    }

    void traverseAndSwap(ListNode*& head) {
        if (!head) {
            return;
        }

        if (!head->next) {
            return;
        }

        ListNode* temp1 = head;
        ListNode* temp2 = head->next->next;
        head = head->next;
        head->next = temp1;
        head->next->next = temp2;

        traverseAndSwap(head->next->next);
    }
};
