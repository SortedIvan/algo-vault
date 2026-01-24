class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() > b.size())
        {
            return addTwoBinaryNr(a, b);
        }
        else
        {
            return addTwoBinaryNr(b, a);
        }

        return "";
    }

    string addTwoBinaryNr(string a, string b)
    {
        // since we assume that a is the bigger number (or equal)
        int leftPointer = a.size() - 1;
        int rightPointer = b.size() - 1;
        std::string result; 
        bool carryOver = false;

        while (leftPointer >= 0 && rightPointer >= 0)
        {
            if (a[leftPointer] == '1' && b[rightPointer] == '1')
            {
                if (carryOver)
                {
                    result = '1' + result;
                }
                else
                {
                    result = '0' + result;
                    carryOver = true;
                }
            }
            else if (a[leftPointer] == '1' && b[rightPointer] == '0')
            {
                if (carryOver)
                {
                    result = '0' + result;
                }
                else
                {
                    result = '1' + result;
                }
            }
            else if (a[leftPointer] == '0' && b[rightPointer] == '1')
            {
                if (carryOver)
                {
                    result = '0' + result;
                }
                else
                {
                    result = '1' + result;
                }
            }
            else // both equal to 0
            {
                if (carryOver)
                {
                    result = '1' + result;
                }
                else
                {
                    result = '0' + result;
                }

                carryOver = false;
            }

            leftPointer--;
            rightPointer--;
        }

        // means there are still numbers in a

        if (!carryOver)
        {
            while (leftPointer >= 0)
            {
                result = a[leftPointer] + result;
                leftPointer--;
            }

            return result;
        }
        else
        {
            while (leftPointer >= 0)
            {
                if (carryOver && a[leftPointer] == '0')
                {
                    carryOver = false;
                    result = '1' + result;
                }
                else if (carryOver && a[leftPointer] == '1')
                {
                    result = '0' + result;
                }
                else if (!carryOver)
                {
                    result = a[leftPointer] + result;
                }

                leftPointer--;
            }
        }

        if (carryOver)
        {
            result = '1' + result;
        }

        return result;
    }
};
