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
    bool isPalindrome(ListNode* head) {
        vector<int> palindromeList;
        collectValuesIntoList(head, palindromeList);
        return checkIfPalindrome(palindromeList);
    }

    bool checkIfPalindrome(vector<int>& palindromeList) {
        int leftPointer = 0;
        int rightPointer = palindromeList.size() - 1;

        while (leftPointer < rightPointer) {
            if (palindromeList[leftPointer] != palindromeList[rightPointer]) {
                return false;
            }

            leftPointer++;
            rightPointer--;
        }

        return true;
    }

    void collectValuesIntoList(ListNode* head, vector<int>& palindromeList) {
        if (!head) {
            return;
        }

        palindromeList.push_back(head->val);

        if (head->next) {
            collectValuesIntoList(head->next, palindromeList);
        }
    }
};
