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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string num1 = "";
        collectNumberToString(l1, num1);
        string num2 = "";
        collectNumberToString(l2, num2);

        string result = "";

        int num1Pointer = num1.size() - 1;
        int num2Pointer = num2.size() - 1;

        addTwoNumbersRecursively(num1, num2, num1Pointer, num2Pointer, result);

        ListNode* resultList = new ListNode();

        int resultPointer = result.size() - 1;

        createResultList(resultList, result, resultPointer);

        return resultList;
    }

    void createResultList(ListNode*& result, string resultStr, int& resultStrPointer)
    {
        if (resultStrPointer < 0)
        {
            return;
        }

        result->val = resultStr[resultStrPointer] - '0';

        if (resultStrPointer - 1 < 0)
        {
            return;
        }


        ListNode* next = new ListNode();

        result->next = next;

        resultStrPointer--;

        createResultList(result->next, resultStr, resultStrPointer);
    }


    void addTwoNumbersRecursively(std::string& num1, std::string& num2, 
    int& num1Pointer, int& num2Pointer, std::string& result)
    {
        if (num1Pointer < 0)
        {
            for (int i = num2Pointer; i >= 0; i--)
            {
                result = num2[i] + result;
            }
            
            return;
        }
        
        if (num2Pointer < 0)
        {
            
            for (int i = num1Pointer; i >= 0; i--)
            {
                result = num1[i] + result;
            }
            
            return;
        }
        
        int resultNr = (num1[num1Pointer] - '0') + num2[num2Pointer] - '0';
        
        if (resultNr < 10)
        {
            result = (char(resultNr + '0')) + result; 
        }
        else 
        {
            result = char((resultNr - 10) + '0') + result;
            carryDigit(num1, num1Pointer - 1, num1Pointer);
        }
        
        num1Pointer--;
        num2Pointer--;
        
        addTwoNumbersRecursively(num1, num2, num1Pointer, num2Pointer, result);
    }
    void carryDigit(string& numToCarryTo, int pointerFrom, int& pointerNum)
    {
        if (pointerFrom < 0)
        {
            numToCarryTo = char(1 + '0') + numToCarryTo;
            
            pointerNum++;
            
            return;
        }

        if (int(numToCarryTo[pointerFrom] - '0') + 1 < 10)
        {
            numToCarryTo[pointerFrom] = char( (int(numToCarryTo[pointerFrom] -'0') + 1) + '0');

            return;
        }

        numToCarryTo[pointerFrom] = '0';
        
        pointerFrom = pointerFrom - 1;

        carryDigit(numToCarryTo, pointerFrom, pointerNum);
    }


    void collectNumberToString(ListNode* node, string& res)
    {
        if (!node)
        {
            return;
        }

        res = char(node->val + '0') + res;
        collectNumberToString(node->next, res);
    }
};
