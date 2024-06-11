class Solution {
public:
    string reversePrefix(string word, char ch) {
        int leftPointer = 0;
        int rightPointer = 0;

        // first, search for the first occurance
        bool found = false;

        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == ch)
            {
                found = true;
                rightPointer = i;
                break;
            }
        }

        if (!found)
        {
            return word;
        }

        while (leftPointer < rightPointer)
        {
            char temp = word[leftPointer];
            word[leftPointer] = word[rightPointer];
            word[rightPointer] = temp;

            leftPointer++;
            rightPointer--;
        }
        
        return word;
    }
};
