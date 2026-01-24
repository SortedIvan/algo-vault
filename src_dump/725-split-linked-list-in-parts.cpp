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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;

        if (!head) {

            while (result.size() < k) {
                result.push_back(nullptr);
            }

            return result;
        }
        
        int linkedListSize = 0;
        countLinkedListSize(head, linkedListSize);

        if (linkedListSize <= k) {
            splitIntoSingles(head, result);

            while (result.size() < k) {
                result.push_back(nullptr);
            }    
        }
        else {
            int size = linkedListSize / k;
            int extraOnes = linkedListSize % k;
            
            while (extraOnes > 0) {
                ListNode* group;
                createGroup(0, size + 1, head, group);
                result.push_back(group);
                extraOnes--;
            }

            while (result.size() < k) {
                ListNode* group;
                createGroup(0, size, head, group);
                result.push_back(group);
            }
        }

        return result;
    }

    void createGroup(int curr,int size, ListNode*& head, ListNode*& group) {
        if (!head) {
            return;
        }

        if (curr == size) {
            return;
        }

        group = new ListNode(head->val);
        head = head->next;
        createGroup(curr+1, size, head, group->next);
    }

    void splitIntoSingles(ListNode*& head, vector<ListNode*>& result) {
        if (!head) {
            return;
        }

        result.push_back(new ListNode(head->val));
        head = head->next;
        splitIntoSingles(head, result);
    }

    void countLinkedListSize(ListNode* head, int& count) {
        if (!head) {
            return;
        }

        count++;
        countLinkedListSize(head->next, count);
    }
};
