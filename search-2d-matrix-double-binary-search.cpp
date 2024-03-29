class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // in order to optimize this, we can first iterate through the entire matrix and in O(n)
        // time check whether the first element and the last element represent the range of 
        // which the target is in

        if (matrix.size() == 1) {
            return BinarySearch(target, 0, matrix[0].size() - 1, matrix[0]);
        }

        int rowToSearch = RowBinarySearch(target, 0, matrix.size() - 1, matrix);

        if (rowToSearch == -1) {
            return false;
        }

        return BinarySearch(target, 0, matrix[rowToSearch].size() - 1, matrix[rowToSearch]);
    }

    int RowBinarySearch(int target, int left, int right, std::vector<std::vector<int>> matrix) {
        if (left > right) {
            return -1;
        }

        int mid = (left + right) / 2;

        if (matrix[mid][0] <= target && target <= matrix[mid][matrix[mid].size() - 1]) {
            return mid;
        }

        if (matrix[mid][matrix[mid].size() - 1] < target) {
            return RowBinarySearch(target, mid + 1, right, matrix);
        }

        if (matrix[mid][0] > target) {
            return RowBinarySearch(target, left, mid - 1, matrix);
        }

        return -1;
    }

    bool BinarySearch(int target, int left, int right, std::vector<int>& row) {
        
        if (left > right) {
            return false;
        }
        
        int mid = (left + right) / 2;

        if (target == row[mid]) {
            return true;
        }

        if (target < row[mid]) {
            return BinarySearch(target, left, mid - 1, row);
        }

        if (target > row[mid]) {
            return BinarySearch(target, mid + 1, right, row);
        }

        return false;
    }

};
