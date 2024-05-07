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
    ListNode* doubleIt(ListNode* head) 
    {
        if (head == nullptr) // Handle edge case of an empty list
            return nullptr;

        // Check if the list has only one node and its value is less than 5
        if (head->next == nullptr && head->val < 5) {
            head->val *= 2;
            return head;
        }
        else if (head->next == nullptr && head->val >= 5)
        {
            int singleDoubled = head->val * 2;
            string singleDoubledStr = std::to_string(singleDoubled);

            head->val = singleDoubledStr[0] - '0';

            ListNode* singleAttach = new ListNode();
            singleAttach->val = singleDoubledStr[1] - '0';
            head->next = singleAttach;

            return head;
        }

        string number = "";
        getNumberToStr(head, number);
        string result = doubleHelper(number);
        
        int pointer = 0;

        convertLinkedListToDoubled(head, result, pointer);

        return head;
    }

    void convertLinkedListToDoubled(ListNode* curr, string& doubledNr, int& pointer)
    {
        if (!curr->next)
        {
            if (pointer < doubledNr.size() - 1)
            {
                ListNode* attach = new ListNode();
                curr->val = doubledNr[pointer] - '0';
                curr->next = attach;
                pointer++;
                convertLinkedListToDoubled(curr->next, doubledNr, pointer);
            }
            else
            {
                curr->val = doubledNr[pointer] - '0';
                return;
            }
        }
        else
        {
            curr->val = doubledNr[pointer] - '0';
            std::cout << pointer;
            pointer++;
            convertLinkedListToDoubled(curr->next, doubledNr, pointer);
        }
    }

    string doubleHelper(string nr)
    {
        int rightPointer = nr.size() - 1;
        string doubled = "";
        bool carryOver = false;

        while (rightPointer >= 0)
        {
            int doubleInt = (nr[rightPointer] - '0') * 2;

            if (rightPointer == 0)
            {

                if (carryOver)
                {

                    doubled = std::to_string(doubleInt + 1) + doubled;
                }
                else
                {
                    doubled = std::to_string(doubleInt) + doubled;
                }
                break;
            }

            if (doubleInt < 10)
            {
                if (doubleInt == 9 && carryOver)
                {
                    doubled = '0' + doubled;
                    carryOver = true;
                    rightPointer--;
                    continue;
                }
                
                if (carryOver)
                {
                    doubled = std::to_string(doubleInt + 1) + doubled;
                    carryOver = false;
                    rightPointer--;
                    continue;
                }

                doubled = std::to_string(doubleInt) + doubled;
                carryOver = false;
                rightPointer--;
            }
            else
            {
                int leftOver = doubleInt % 10;
                if (carryOver)
                {
                    doubled = std::to_string(leftOver + 1) + doubled;
                }
                else
                {

                    doubled = std::to_string(leftOver) + doubled;
                }

                carryOver = true;
                rightPointer--;
            }
        }
        return doubled;
    }

    void getNumberToStr(ListNode* curr, string& collect) 
    {
        if (!curr->next)
        {
            collect += std::to_string(curr->val);
            return;    
        }

        collect += std::to_string(curr->val);
        getNumberToStr(curr->next, collect);
    }
};
