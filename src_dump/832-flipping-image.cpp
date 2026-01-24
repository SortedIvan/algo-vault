class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        // [0,0,1]      [0, 1, 1]
        // [1,0,1] ->   [0, 1, 0]
        // [1,0,0]      [1, 1, 0]

        for (int i = 0; i < image.size(); ++i) {
            int left = 0;
            int right = image[i].size() - 1;

            while (left <= right) {
                int temp = image[i][left];
                image[i][left] = flip(image[i][right]);
                image[i][right] = flip(temp);

                left++;
                right--;
            }
        }

        return image;
    }

    int flip(const int& val) {
        if (val == 0) {
            return 1;
        }
        return 0;
    }
};
