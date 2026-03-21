class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = y; i < y + k; ++i) {
            int col_num = i;
            int row_num_start_ptr = x;
            int row_num_end_ptr = x + k - 1;

            while (row_num_start_ptr <= row_num_end_ptr) {
                int copy = grid[row_num_start_ptr][col_num];
                grid[row_num_start_ptr][col_num] = grid[row_num_end_ptr][col_num];
                grid[row_num_end_ptr][col_num] = copy;

                row_num_start_ptr++;
                row_num_end_ptr--;
            }  
        }

        return grid;
    }
};
