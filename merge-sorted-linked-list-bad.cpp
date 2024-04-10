
#include <utility>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result =  new ListNode();

        if (!list1 && list2) {
            return list2;
        }

        if (!list2 && list1) {
            return list1;
        }

        if (!list2 && !list1) {
            return nullptr;
        }

        merge(result, list1, list2);

        return result;
    }

    void merge(ListNode* result, ListNode* left, ListNode* right) {
        if (!left) {
            if (!right) {
                return;
            }
            copyOverRest(result, right);
            return;
        }

        if (!right) {
            if (!left) {
                return;
            }
            copyOverRest(result, left);
            return;
        }

        if (left->val >= right->val) {
            result->val = right->val;
            ListNode* next = new ListNode();
            result->next = next;
            merge(next, left, right->next);
        }
        else if(right->val > left->val) {
            result->val = left->val;
            ListNode* next = new ListNode();
            result->next = next;
            merge(next, right, left->next);
        }
    }

    void copyOverRest(ListNode* result, ListNode* remaining) {
        if (!remaining) {
            return;
        }

        if (!remaining->next) {
            ListNode* next = new ListNode();
            result->val = remaining->val;
            result->next = nullptr;
            return;
        }

        ListNode* next = new ListNode();
        result->val = remaining->val;
        result->next = next;
        copyOverRest(next, remaining->next);
    }
};
