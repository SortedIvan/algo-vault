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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (!head) {
            return nullptr;
        }

        unordered_set<int> remove;

        for (int i = 0; i < nums.size(); ++i) {
            remove.insert(nums[i]);
        }

        if (!head->next && remove.find(head->val) != remove.end()) {
            return nullptr;
        } 

        ListNode* newHead = nullptr;
        removeBadNodes(remove, head, newHead);
        return newHead;
    }

    void removeBadNodes(unordered_set<int>& remove, ListNode* head, ListNode*& newHead) {
        if (!head) {
            return;
        }

        if (remove.find(head->val) == remove.end()) {
            newHead = new ListNode(head->val);   
            removeBadNodes(remove, head->next, newHead->next);
        }
        else {
            removeBadNodes(remove, head->next, newHead);
        }
        
    }
};
