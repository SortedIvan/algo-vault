class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int leftPointer = 0;
        int rightPointer = numbers.size() - 1;
        std::vector<int> result;

        while (leftPointer < rightPointer) {
            if (numbers[leftPointer] + numbers[rightPointer] == target){
                result.push_back(leftPointer+1);
                result.push_back(rightPointer+1);
                return result;
            }

            if (numbers[leftPointer] + numbers[rightPointer] > target) {
                rightPointer--;
                continue;
            }

            if (numbers[leftPointer] + numbers[rightPointer] < target) {
                leftPointer++;
                continue;
            }
        }

        return result;
    }
};
