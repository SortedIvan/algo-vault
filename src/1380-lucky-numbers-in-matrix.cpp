class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        if (!matrix.size()) {
            return vector<int>();
        }
        
        set<int> biggestNrInCol;
        int colPointer = 0;

        while (colPointer < matrix[0].size()) {
            
            int biggest = matrix[0][colPointer];
            
            for (int i = 0; i < matrix.size(); ++i) {
                biggest = std::max(biggest, matrix[i][colPointer]);
            } 
            
            biggestNrInCol.insert(biggest);
            colPointer++;
        }

        vector<int> result;

        for (int i = 0; i < matrix.size(); ++i) {

            int smallest = matrix[i][0];

            for (int k = 0; k < matrix[i].size(); ++k) {
                smallest = std::min(smallest, matrix[i][k]);
            }

            if (biggestNrInCol.find(smallest) != biggestNrInCol.end()) {
                result.push_back(smallest);
            }
        }

        return result;
    }
};
