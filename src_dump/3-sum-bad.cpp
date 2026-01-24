#include <map>
#include <array>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;

        std::map<int,std::array<int, 3>> indexer;
        std::map<std::array<int, 3>, int> duplicateChecker;
        std::set<std::vector<int>> resultSet;
        if (nums.size() < 3) {
            return result;
        }

        nums = MergeSort(nums);

        for (int i = 0; i < nums.size(); i++) {
            if (indexer.find(nums[i]) != indexer.end()) {
                if (indexer[nums[i]][1] == -1) {
                    indexer[nums[i]][1] = i;
                }
                else {
                    indexer[nums[i]][2] = i; 
                }
            }
            else {
                std::array<int, 3> toPush{{i, -1, -1}};
                indexer.insert({nums[i], toPush});
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int k = i + 1; k < nums.size(); k++) {
                int sum = nums[i] + nums[k];
                if (indexer.find(-sum) != indexer.end()) {
                    for (int idx : indexer[-sum]) 
                    {
                        if (idx != -1 && idx != i && idx != k)                         {
                            vector<int> vec{nums[i], nums[k], nums[indexer[-sum][0]]};
                            sort(vec.begin(), vec.end());
                            resultSet.insert({vec});
                            break;
                        }
                    }

                }
            }
        }


        std::vector<std::vector<int>> result2(resultSet.begin(), resultSet.end());

        return result2;
    }

    vector<int> MergeSort(vector<int> input){
        
        if (input.size() == 1) {
            return input;
        }

        int mid = input.size() / 2;

        vector<int> leftHalf(mid);
        vector<int> rightHalf(input.size() - mid);

        for (int i = 0; i < mid; i++) {
            leftHalf[i] = input[i];
        }

        for (int i = 0; i < input.size() - mid; i++) {
            rightHalf[i] = input[mid + i];
        }

        leftHalf = MergeSort(leftHalf);
        rightHalf = MergeSort(rightHalf);

        return Merge(leftHalf, rightHalf);
    }

    vector<int> Merge(vector<int> left, vector<int> right){
        int leftPointer = 0;
        int rightPointer = 0;
        int resultPointer = 0;

        vector<int> result(left.size() + right.size());

        while (leftPointer < left.size() && rightPointer < right.size()) {
            if (left[leftPointer] < right[rightPointer]) {
                result[resultPointer] = left[leftPointer];
                resultPointer++;
                leftPointer++; 
            }
            else {
                result[resultPointer] = right[rightPointer];
                resultPointer++;
                rightPointer++; 
            }
        }

        // copy any leftovers
        while (leftPointer < left.size()) {
            result[resultPointer] = left[leftPointer];
            resultPointer++;
            leftPointer++; 
        }

        while (rightPointer < right.size()) {
            result[resultPointer] = right[rightPointer];
            resultPointer++;
            rightPointer++; 
        }

        return result;
    }

};
