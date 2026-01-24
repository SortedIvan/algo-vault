class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int oddCounter = 0;
        
        for (int i = 0; i < arr.size(); ++i) {
            if (oddCounter == 3) {
                return true;
            }
            
            if (arr[i] % 2 != 0) {
                oddCounter++;
            } else {
                oddCounter = 0;
            }
        }

        if (oddCounter == 3) {
            return true;
        }

        return false;
    }
};
