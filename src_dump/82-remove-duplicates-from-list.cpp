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
        fixList(nullptr, head);
        return head;
    }

    void fixList(ListNode* prev, ListNode*& head) {
        if (!head) {
            return;
        }

        ListNode* end = findEnd(head->next, head->val);

        if (end != head->next) {
            if (prev == nullptr) {
                head = end;
                fixList(nullptr, head);
            } else {
                prev->next = end;
                fixList(prev, end);
            }
        } else {
            // No duplicates, move to the next node
            fixList(head, head->next);
        }
    }

    ListNode* findEnd(ListNode* head, int val) {
        while (head && head->val == val) {
            head = head->next;
        }

        return head;
    }
};
