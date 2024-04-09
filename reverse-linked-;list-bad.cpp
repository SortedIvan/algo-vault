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

#include <vector>

class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        if (!head) 
        {
            return nullptr;
        }

        if (!head->next) 
        {
            return head;
        }    

        std::vector<int> values;
        values.push_back(head->val);

        extractValues(values, head->next, head);

        int pointer = values.size() - 1;
        
        reverseValues(values, head, pointer);

        return head;
    }   

    void reverseValues(std::vector<int>& values, ListNode* curr, int& pointer) 
    {
        if (!curr) 
        {
            return;
        }

        curr->val = values[pointer];
        pointer--;

        reverseValues(values, curr->next, pointer);
    }

    ListNode* extractValues(std::vector<int>& values, ListNode* curr, ListNode* previous) 
    {
        
        if (!curr) 
        {
            return previous;
        }

        values.push_back(curr->val);

        return extractValues(values, curr->next, curr);
    }
};
