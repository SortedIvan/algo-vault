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
    ListNode* removeNodes(ListNode* head) {
        ListNode* result = new ListNode();
        ListNode* resultHeadPtr = new ListNode();
        resultHeadPtr = result;

        vector<int> linkedListValues;
        collectListNodeValues(head, linkedListValues);
        vector<int> biggestValuesIndexer = vector<int>(linkedListValues.size());
        
        int biggestSoFar = linkedListValues[linkedListValues.size() - 1];
        for (int i = linkedListValues.size() - 1; i >= 0; i--) {
            if (biggestSoFar < linkedListValues[i]) {
                biggestSoFar = linkedListValues[i];
            }

            biggestValuesIndexer[i] = biggestSoFar;
        }

        for (int k = 0; k < linkedListValues.size(); ++k) {
            if (k == linkedListValues.size() - 1) {
                result->val = linkedListValues[k];
                break;
            }

            if (linkedListValues[k] < biggestValuesIndexer[k + 1]) {
                continue;
            }

            result->val = linkedListValues[k];
            result->next = new ListNode();
            result = result->next;
        }
        

        return resultHeadPtr;
    }

    void collectListNodeValues(ListNode* head, vector<int>& linkedListValues) {
        if (!head) {
            return;
        }

        linkedListValues.push_back(head->val);
        collectListNodeValues(head->next, linkedListValues);
    }
};
