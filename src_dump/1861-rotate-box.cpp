class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        for (int i = 0; i < box.size(); ++i) {
            int pointer = box[i].size() - 1;
            int temp = 0;

            while (pointer >= 0) {
                char element = box[i][pointer];
                temp = pointer;
                if (element == '#') {
                    for (int k = pointer + 1; k < box[i].size(); ++k) {
                        if (box[i][k] == '.') {
                            // move right once
                            box[i][temp] = '.';
                            box[i][k] = '#';
                            temp++;
                        }
                        else {
                            break;
                        }
                    }
                }

                pointer--;
            }
        }

        // rotate the "box"
        vector<vector<char>> result(box[0].size());
        for (int i = box.size() - 1; i >= 0; --i) {
            for (int k = 0; k < box[i].size(); ++k) {
                result[k].push_back(box[i][k]);
            }
        }

        return result;
    }
};
