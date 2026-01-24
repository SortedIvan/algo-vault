class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        return findPeak(arr);
    }

    int findPeak(vector<int>& arr) {
        int left = 1;
        int right = arr.size() - 2;
        int mid = (left + right) / 2;

        while (left <= right) {
            mid = (left + right) / 2;

            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid+1]) {
                return mid;
            }

            if (arr[mid] < arr[mid + 1]) {
                // go right
                left = mid + 1;
                continue;
            }

            if (arr[mid - 1] > arr[mid]) {
                // go left
                right = mid - 1;
                continue;
            }
        }

        return -1;
    }
};
