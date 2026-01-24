class Solution {
public:
    static int mapNumber(int num, const vector<int>& mapping) {
        int counter = 1;
        int mappedInteger = 0;

        if (num == 0) {
            return mapping[0];
        }

        while (num > 0)
        {
            int currentDigit = num % 10;
            int mappedDigit = mapping[currentDigit];
            mappedInteger += (mappedDigit * counter);
            counter *= 10; 
            num = num / 10;
        }

        return mappedInteger;
    }

    static bool comparator(int num1, int num2, const vector<int>& mapping) {
        int mappedNr1 = mapNumber(num1, mapping);
        int mappedNr2 = mapNumber(num2, mapping);
        return mappedNr1 < mappedNr2;
    } 

    static vector<int> sortJumbled(const vector<int>& mapping, vector<int>& nums) {

        std::cout << mapNumber(0, mapping) << std::endl;

        std::sort(nums.begin(), nums.end(), [&mapping](int num1, int num2) {
            return comparator(num1, num2, mapping);
        });
        return nums;
    }
};
