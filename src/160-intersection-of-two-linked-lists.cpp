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
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> nodeMap;
        return findIntersection(nodeMap,headA, headB);
    }

    ListNode* findIntersection(unordered_map<ListNode*, int>& nodeMap, ListNode* headA, ListNode* headB) {
        while (headA || headB) {
            if (headA == headB && headA && headB) {
                return headA;
            }

            if (nodeMap.find(headA) != nodeMap.end()) {
                return headA;
            }

            if (nodeMap.find(headB) != nodeMap.end()) {
                return headB;
            }

            if (headA) {
                nodeMap.insert({headA, 1});
                headA = headA->next;
            }

            if (headB) {
                nodeMap.insert({headB, 1});
                headB = headB->next;
            }
        }

        return nullptr;
    }
};
