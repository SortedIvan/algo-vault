class Solution {
public:
    string getEncryptedString(string s, int k) {
        // for every character in s, replace it with its corresponding character after 
        // k positions. The action is cyclic 

        string encryptionCopy = s;
        int positionsToMove = k % s.size();

        for (int i = 0; i < s.size(); ++i) {
            if (i + positionsToMove >= s.size()) {
                int remainderFromStart = (i + positionsToMove) - s.size();
                s[i] = encryptionCopy[remainderFromStart];
            }
            else {
                s[i] = encryptionCopy[i + positionsToMove];
            }
        }

        return s;
    }
};
