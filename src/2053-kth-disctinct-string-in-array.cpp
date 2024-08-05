class Solution {
public:
    // idea: store the strings and their occurances. 
    // If the string already exists in the char map, its not a disctinct string, mark it as -1
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> charMap;
        map<int, string> indexMap;

        for (int i = 0; i < arr.size(); ++i) {
            if (charMap.find(arr[i]) != charMap.end()) {
                // word already exists in array, mark as -1

                if (charMap[arr[i]] == -1) {
                    continue;
                }

                indexMap.erase(charMap[arr[i]]);
                charMap[arr[i]] = -1;

            } else {
                charMap.insert({arr[i], i});
                indexMap.insert({i, arr[i]});
            }
        }

        int counter = 0;

        for (auto word : indexMap) {
            if (counter == k - 1) {
                return word.second;
            }
            counter++;
        }


        return "";
    }
};
