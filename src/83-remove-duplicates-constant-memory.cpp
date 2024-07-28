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
    ListNode* deleteDuplicates(ListNode* head) {
        iterateOverLinkedList(head);
        return head;
    }

    void iterateOverLinkedList(ListNode*& head) {
        if (!head) {
            return;
        }

        int val = head->val;
        ListNode* end = findDuplicatesEnd(head->next, val);

        if (!end) {
            head->next = nullptr;
        }
        else {
            head->next = end;
            iterateOverLinkedList(head->next);
        }
    }

    ListNode* findDuplicatesEnd(ListNode* head, int val) {
        while (head && head->val == val) {
            head = head->next;
        }

        return head;
    }

};
