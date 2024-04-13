#include <map>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {   
        if (!head || !head->next) 
        {
            return false;
        }

        head->val = std::numeric_limits<int>::max();

        return checkForCycle(head->next);
    }

    bool checkForCycle(ListNode* curr) 
    {
        if (!curr->next) 
        {
            return false;
        }

        if (curr->next->val == std::numeric_limits<int>::max())
        {
            return true;
        }

        curr->val = std::numeric_limits<int>::max();

        return checkForCycle(curr->next);
    }
};
