class Solution {
public:
    int findComplement(int num) {
        string numBinary = bitset<32>(num).to_string();
        string numComplementBinary = "";
        int numPointer = 0;

        while (numPointer < numBinary.size()) {
            if (numBinary[numPointer] == '1') {
                break;
            }
            numPointer++;
        }

        while (numPointer < numBinary.size()) {
            if (numBinary[numPointer] == '1') {
                numComplementBinary.push_back('0');
            }
            else {
                numComplementBinary.push_back('1');
            }
            numPointer++;
        }
        return std::stol(numComplementBinary,0,2);
    } 
};
