class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // First, count the sub arrays and push their sizes into a map
        // Go over the numbers and do n(n+1)/2
        long long result = 0;
        unordered_map<int, int> subArrayMap;
        int currSubarraySize = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                currSubarraySize++;
            }
            else {
                if (currSubarraySize > 0) {
                    subArrayMap[currSubarraySize]++;
                    currSubarraySize  = 0;
                }
            }
        }

        if (currSubarraySize > 0) {
            subArrayMap[currSubarraySize]++;
        }

        for (auto pair : subArrayMap) {
            result += getSubarraySum(pair.first, pair.second);
        }   

        return result;
    }

    long long getSubarraySum(long long size, long long times) {
        long long n = (size * (size + 1)) / 2;
        return n * times;
    }
};
