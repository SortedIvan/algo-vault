class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> result;
        int numOnePointer = 0;
        int numTwoPointer = 0;

        while (numOnePointer < nums1.size() && numTwoPointer < nums2.size()) {
            if (nums1[numOnePointer][0] == nums2[numTwoPointer][0]) {
                result.push_back(
                    { 
                        nums1[numOnePointer][0],
                        nums1[numOnePointer][1] + nums2[numTwoPointer][1] 
                    }
                );
                
                numOnePointer++;
                numTwoPointer++;
            }
            else if (nums1[numOnePointer][0] < nums2[numTwoPointer][0]) {
                result.push_back(nums1[numOnePointer]);
                numOnePointer++;
            }
            else {
                result.push_back(nums2[numTwoPointer]);
                numTwoPointer++;
            }
        }

        // copy over any leftovers

        while (numOnePointer < nums1.size()) {
            result.push_back(nums1[numOnePointer]);
            numOnePointer++;
        }

        while (numTwoPointer < nums2.size()) {
            result.push_back(nums2[numTwoPointer]);
            numTwoPointer++;
        }

        return result;
    }

};
