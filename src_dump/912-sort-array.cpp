class Solution {
public:
    // merge sort
    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums);
    }

    vector<int> mergeSort(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return nums;
        }

        int leftSize = nums.size() / 2;
        int rightSize = nums.size() - leftSize;
        vector<int> left(leftSize);
        vector<int> right(rightSize);

        for (int i = 0; i < leftSize; ++i) {
            left[i] = nums[i];
        }

        for (int i = 0; i < rightSize; ++i) {
            right[i] = nums[i + leftSize];
        }   

        left = mergeSort(left);
        right = mergeSort(right);

        return merge(left, right);
    }

    vector<int> merge(vector<int>& left, vector<int>& right) {
        vector<int> result(left.size() + right.size());
        int leftPointer = 0;
        int rightPointer = 0;
        int resultPointer = 0;

        while (leftPointer < left.size() && rightPointer < right.size()) {
            if (left[leftPointer] < right[rightPointer]) {
                result[resultPointer] = left[leftPointer];
                resultPointer++;
                leftPointer++;
            } else {
                result[resultPointer] = right[rightPointer];
                resultPointer++;
                rightPointer++;
            }
        }

        // copy over any left over elements
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
