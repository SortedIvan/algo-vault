class Solution {
public:
    int getLucky(string s, int k) {
        // - 96
        std::string number = "";
        for (int i = 0; i < s.size(); ++i) {
            int res = int(s[i]) - 96;
            number += std::to_string(res);
        }

        while (k > 0) {
            k--;
            int temp = 0;
            for (int i = 0; i < number.size(); ++i) {
                temp += (number[i] - '0');
            }
            number = std::to_string(temp);
        }
        
        return std::stoi(number);
    }
};
