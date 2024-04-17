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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if (!head) 
        {
            return head;
        }

        int amountOfNodes = 1;

        ListNode* tail = findTailAndCount(head, amountOfNodes);

        if (amountOfNodes == 1) 
        {
            return nullptr;
        }

        int indexToRemove = (amountOfNodes - n) + 1;

        int counter = 1;

        if (indexToRemove == counter) 
        {
            // removing the start of the list
            return head->next;
        }

        removeSelectedNode(counter, indexToRemove, head, nullptr);

        return head;
    }

    void removeSelectedNode(int& counter, int indexToRemove, ListNode* curr, ListNode* prev)
    {
        if (counter == indexToRemove)
        {
            if (!curr->next) 
            {
                // we are removing the last node, simply set prev to nullptr
                prev->next = nullptr;
                return;
            }


            prev->next = curr->next;
            return;
        }

        counter++;
        removeSelectedNode(counter, indexToRemove, curr->next, curr);
    }

    ListNode* findTailAndCount(ListNode* curr, int& counter) 
    {
        if (!curr->next)
        {
            return curr;
        }

        counter++;
        return findTailAndCount(curr->next, counter);
    }
};
