class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        std::vector<long long> result;
        long long leftover = num % 3;

        if (leftover == 0) {
            long long divided = num / 3;
            
            result.push_back(divided - 1);
            result.push_back(divided);
            result.push_back(divided + 1);
        }
        else {
            long long dividableNum = num - leftover;
            long long divided = dividableNum / 3;

            if (dividableNum <=0) {
                return std::vector<long long>();
            }
            
            result.push_back(divided - leftover);
            result.push_back(divided);
            result.push_back(divided + leftover);
            
        }

        if (addsUpToNumber(result, num)) {
            return result;
        }

        return std::vector<long long>();
    }

    bool addsUpToNumber(const std::vector<long long>& result, long long num) {
        long long sum = 0;
        for (int i = 0; i < result.size(); ++i) {
            sum += result[i];
        }

        return sum == num;
    }
};
