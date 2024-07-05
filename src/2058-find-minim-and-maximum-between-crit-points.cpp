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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> result;

        int minDistance = std::numeric_limits<int>::max();
        int maxDistance = std::numeric_limits<int>::min();
        int counter = 1;
        int criticalPointsCounter = 0;
        int firstCrit = 0;
        int prevCrit = 0;
        
        findCriticalPoints(head, nullptr, minDistance, maxDistance, counter, criticalPointsCounter, firstCrit, prevCrit);

        if (criticalPointsCounter < 2) {
            return std::vector<int> {-1, -1};
        }

        result = {minDistance, maxDistance};

        return result;
    }

    void findCriticalPoints(ListNode* head, ListNode* prev, int& minDistance, int& maxDistance, int counter, int& criticalPointsCounter, int& firstCrit, int& prevCrit) {
        
        if (!head) {
            return;
        }

        if (!prev) {
            findCriticalPoints(head->next, head, minDistance, maxDistance, counter + 1, criticalPointsCounter, firstCrit, prevCrit);
            return;
        }

        if (!head->next) {
            return;
        }

        int nextValue = head->next->val;
        int prevValue = prev->val;

        if ((prevValue < head->val && nextValue < head->val)
            || (prevValue > head->val && head->val < nextValue )) {
                // critical point
            criticalPointsCounter++;

            if (criticalPointsCounter > 1) {
                maxDistance = std::max(counter - firstCrit, maxDistance);
                minDistance = std::min(counter - prevCrit, minDistance);
                prevCrit = counter;
            } else {
                firstCrit = counter;
                prevCrit = counter;
            }
        } 

        findCriticalPoints(head->next, head, minDistance, maxDistance, counter + 1, criticalPointsCounter, firstCrit, prevCrit);
    }

    
};
