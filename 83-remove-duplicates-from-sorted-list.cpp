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

        if (!head) {
            return nullptr;
        }

        map<int, int> alrExists;
        ListNode* result = new ListNode();
        clearList(head, result, alrExists);
        return result;
    }

    void clearList(ListNode* head, ListNode*& result, map<int, int> alrExists) {
        if (alrExists.find(head->val) == alrExists.end()) {
            ListNode* attach = new ListNode();
            attach->val = head->val;
            result = attach;
            alrExists.insert({head->val, 1});
        }

        if (!head->next) {
            return;
        }

        if (!result) {
            clearList(head->next, result, alrExists);
        } else {
            clearList(head->next, result->next, alrExists);
        }
    
    }

};
