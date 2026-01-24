class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (letters.size() == 1) {
            return letters[0];
        }

        return find(letters, 0, letters.size() - 1, target);
    }

    char find(vector<char>& letters, int left, int right, char target) {
        
        if (left > right) {
            return letters[0];
        }
        
        int mid = (left + right) / 2;

        if (letters[mid] == target) {
            if (mid == letters.size() - 1) {
                return letters[0];
            } 

            if (letters[mid + 1] == target) {
                // search further right
                return find(letters, mid + 2, right, target);
            }

            return letters[mid + 1];
        }

        if (letters[mid] < target) {
            // go right
            return find(letters, mid + 1, right, target);
        }

        if (letters[mid] > target) {
            // go left
            if (mid != 0) {
                if (letters[mid - 1] <= target) {
                    return letters[mid];
                }
            }

            return find(letters, left, mid - 1, target);
        }

        return letters[0];
    }

};
