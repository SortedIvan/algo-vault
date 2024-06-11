class Solution {
public:
    int appendCharacters(string s, string t) {
        // s and t are only lowercase
        // return minimum chars to append at end of s so that t becomes subsequence of s

        int sPointer = 0;
        int tPointer = 0;

        while (sPointer < s.size() && tPointer < t.size()) {
            if (s[sPointer] == t[tPointer]) {
                sPointer++;
                tPointer++;
            } else {
                sPointer++;
            }
        } 

        return t.size() - tPointer;
    }
};
