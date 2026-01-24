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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return nullptr;
        }

        if (k == 0 || !head->next) {
            return head;
        }

        int nrOfNodes = getSizeOfList(head);
        int nrOfActualRotations = k % nrOfNodes;

        if (nrOfActualRotations == 0) {
            return head;
        }

        int nodesToTakeFromFront = nrOfNodes - nrOfActualRotations;
        ListNode* resultHead = nullptr;
        rotate(nodesToTakeFromFront, head, vector<int>(), 0, resultHead);
        return resultHead;
    }

    void rotate(int nrOfNodesFromFront, ListNode* head, vector<int> collectedNodes, int counter, ListNode*& resultHead) {
        if (counter < nrOfNodesFromFront) {
            collectedNodes.push_back(head->val);
            rotate(nrOfNodesFromFront, head->next, collectedNodes, counter + 1, resultHead);
        } else {
            resultHead = head;
            while (head->next) {
                head = head->next;
            }
            
            int pointer = 0;
            while (pointer < collectedNodes.size()) {
                head->next = new ListNode(collectedNodes[pointer]);
                head = head->next;
                pointer++;
            }
        }
    }

    int getSizeOfList(ListNode* head) {
        int counter = 0;
        while (head) {
            counter++;
            head = head->next;
        }
        return counter;
    }
};
