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
    ListNode* reverseList(ListNode* head) {
        if (!head)
        {
            return nullptr;
        }    

        if (!head->next)
        {
            return head;
        }
        
        return  reverseHelper(nullptr, head);
    }

    ListNode* reverseHelper(ListNode* prev, ListNode* curr)
    {
        if (!curr->next)
        {
            // reached the end
            curr->next = prev;
            return curr;
        }
        else
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            return reverseHelper(curr, temp);
        }
    }
};
