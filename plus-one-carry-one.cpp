class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        if (digits[digits.size() - 1] + 1 < 10)
        {
            digits[digits.size() - 1] += 1;
            return digits;
        }

        int pointer = digits.size() - 1;
        
        carryDigit(digits, pointer);

        return digits;
    }

    void carryDigit(vector<int>& digits, int& pointer)
    {
        if (pointer < 0)
        {
            digits.insert(digits.begin(), 1);
            return;
        }

        if (digits[pointer] + 1 < 10)
        {
            digits[pointer] += 1;
            return;
        }

        digits[pointer] = 0;
        pointer--;
        carryDigit(digits,pointer);
    
    }
};
