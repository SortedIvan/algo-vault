class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if (haystack == needle) {
            return 0;
        }

        if (haystack.size() < needle.size()) {
            return -1;
        }

        int hayPointer = 0;
        int needlePointer = 0;
        int revertTo = -1;

        if (needle.size() - 1 == 0) 
        {
            for (int i = 0; i < haystack.size(); i++) 
            {
                if (haystack[i] == needle[0]) {
                    return i;
                }
            }
        }

        while (needlePointer < needle.size())
        {
            if (hayPointer >= haystack.size()) 
            {
                break;
            }

            if (haystack[hayPointer] == needle[needlePointer])
            {
                
                if (needlePointer == needle.size() - 1) {
                    break;
                }


                if (revertTo == -1) 
                {
                    revertTo = hayPointer + 1;
                    if (revertTo >= haystack.size()) 
                    {

                        break;
                    }
                }

                hayPointer++;
                needlePointer++;    

                continue;
            }

            if (haystack[hayPointer] != needle[needlePointer]) 
            {
                if (revertTo == -1) 
                {
                    if (hayPointer == haystack.size() - 1) {
                        break;
                    }

                    needlePointer = 0;
                    hayPointer++;
                    continue;
                }

                needlePointer = 0;
                hayPointer = revertTo;
                revertTo = -1;
            }
        }

        if (needle.size() - 1 == needlePointer && haystack[hayPointer] == needle[needlePointer]) 
        {
            return revertTo - 1;
        }

        return -1;
    }
};
