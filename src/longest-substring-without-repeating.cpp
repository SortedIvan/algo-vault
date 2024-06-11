class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int biggest = 1;
        int leftPointer = 0;
        int rightPointer = 1;
        int counter = 1;

        std::map<char, int> characterMap;

        if (s.size() == 0)
        {
            return 0;
        }

        if (s.size() == 1)
        {
            return 1;
        }

        characterMap.insert({s[leftPointer], 1});

        while (rightPointer < s.size())
        {
            if (characterMap.find(s[rightPointer]) != characterMap.end())
            {
                // the character already exists, remove one from the left pointer

                characterMap.erase(s[leftPointer]);

                leftPointer++;

                counter--;

                if (leftPointer == rightPointer)
                {
                    characterMap.insert({s[leftPointer], 1});
                    rightPointer++;
                    counter = 1;
                }
            }
            else
            {
                characterMap.insert({s[rightPointer], 1});
                rightPointer++;
                counter++;

                if (counter > biggest)
                {
                    biggest = counter;
                }
            }
        }

        return biggest;    
    }
};
