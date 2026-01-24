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
    ListNode* swapNodes(ListNode* head, int k) {
        
        if (!head) {
            return nullptr;
        }

        if (!head->next) {
            return head;
        }

        int nodeCount = countNodes(head, 0);
        int k2 = (nodeCount - (k - 1));

        ListNode* k1Node = getKthNode(head, 1, k);
        ListNode* k2Node = getKthNode(head, 1, k2);

        int temp = k1Node->val;
        k1Node->val = k2Node->val;
        k2Node->val = temp;

        return head;
    }

    ListNode* getKthNode(ListNode* head, int counter, int k) {
        if (counter == k) {
            return head;
        }

        counter++;
        return getKthNode(head->next, counter, k);
    }

    int countNodes(ListNode* head, int counter) {
        if (!head) {
            return counter;
        }

        counter++;
        return countNodes(head->next, counter);
    }

};
