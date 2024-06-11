class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // in order to optimize this, we can first iterate through the entire matrix and in O(n)
        // time check whether the first element and the last element represent the range of 
        // which the target is in
        
        int rowToSearch = -1;

        for (int i = 0; i < matrix.size(); i++) {
            int leftRange = matrix[i][0];
            int rightRange = matrix[i][matrix[i].size() - 1];
            
            if (leftRange == target){
                return true;
            }

            if (rightRange == target) {
                return true;
            }

            if (leftRange < target && target < rightRange) {
                rowToSearch = i;
                break;
            }
        }

        if (rowToSearch == -1) {
            return false;
        }

        return BinarySearch(target, 0, matrix[rowToSearch].size() - 1, matrix[rowToSearch]);
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
