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
    ListNode *detectCycle(ListNode *head) 
    {
        if (!head || !head->next)
        {
            return nullptr;
        }

        map<ListNode*, int> indexMap;
        
        return findCycle(head, indexMap);
    }      

    ListNode* findCycle(ListNode* curr, map<ListNode*, int>& indexMap)
    {
        if (!curr->next)
        {
            return nullptr;
        }

        // Already exists in the map
        if (indexMap.find(curr) != indexMap.end())
        {
            return curr;
        }

        indexMap.insert({curr, 1});

        return findCycle(curr->next, indexMap);
    }

};
