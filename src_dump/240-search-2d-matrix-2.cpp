class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] == target) {
                return true;
            }

            if (matrix[i][matrix[i].size() - 1] == target) {
                return true;
            }

            if (matrix[i][0] < target && target < matrix[i][matrix[i].size() - 1]) {
                bool res = binarySearch(target, 0, matrix[i].size() - 1, matrix[i]);
                if (res) {
                    return true;
                }
            }

            if (matrix[i][0] > target) {
                return false;
            }
        }

        return false;
    }

    bool binarySearch(int target, int left, int right, const vector<int>& arr) {
        std::cout << " HI" << std::endl;
        int mid = (left + right) / 2;

        if (left > right) {
            return false;
        }
        else if (left == right) {
            if (arr[mid] == target) {
                return true;
            }
        }


        if (arr[mid] == target) {
            return true;
        }

        if (arr[mid] < target) {
            // go left
            return binarySearch(target, mid + 1, right, arr);
        }

        return binarySearch(target, left, mid - 1, arr);
    }
};
