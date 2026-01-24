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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        
        int size = 0;
        countLinkedListSize(head, size);

        if (size == 1) {
            return nullptr;
        }

        int mid = size / 2;

        if (mid == 0) {
            return head->next;
        }

        std::cout << mid << std::endl;

        ListNode* prev = nullptr;
        removeMiddleNode(mid, head, prev, 0);

        return head;
    }

    void removeMiddleNode(int mid, ListNode*& head, ListNode*& prev, int counter) {
        if (!head) {
            return;
        }

        if (counter == mid) {
            prev->next = head->next;
            return;
        }

        counter++;
        removeMiddleNode(mid, head->next, head, counter);
    }

    void countLinkedListSize(ListNode* head, int& counter) {
        if (!head) {
            return;
        }
        counter++;
        countLinkedListSize(head->next, counter);
    } 
};
