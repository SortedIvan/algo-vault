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
    ListNode* mergeNodes(ListNode* head) {
        
        if (!head) {
            return nullptr;
        }


        ListNode* result = new ListNode();
        int sum = 0;
        populateResultList(result, head->next, sum);
        
        return result;
    }

    void populateResultList(ListNode*& result, ListNode* head, int& sum) {
        if (!head) {
            return;
        }
        if (head->val != 0) {
            sum += head->val;
            populateResultList(result, head->next, sum);
        } else {
            ListNode* attach = new ListNode();
            attach->val = sum;
            sum = 0;
            result = attach;
            populateResultList(result->next, head->next, sum);
        }
    }
};
