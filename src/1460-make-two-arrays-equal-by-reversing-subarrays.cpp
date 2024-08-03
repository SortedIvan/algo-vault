class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int targetPointer = 0;
        int movePointer = 0;

        if (arr.size() != target.size()) {
            return false;
        }

        while (targetPointer < target.size() && movePointer < arr.size()) {
            if (target[targetPointer] == arr[movePointer]) {
                swapArray(arr, targetPointer, movePointer);
                targetPointer++;
                movePointer = targetPointer;
            } else {
                movePointer++;
            }
        }

        if (targetPointer != target.size()) {
            return false;
        }

        return true;
    }

    void swapArray(vector<int>& arr, int left, int right) {
        while (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
};
