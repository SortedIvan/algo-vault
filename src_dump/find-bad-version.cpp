// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int currentBadVersion = 1;
        return findBadVersion(1, n, currentBadVersion);
    }

    int findBadVersion(int left, int right, int& currentBadVersion) 
    {
        int mid = left + (right - left) / 2;

        if (left > right) 
        {
            return currentBadVersion;
        }

        if (isBadVersion(mid))
        {
            // edge case if its the first bad version
            if (mid == 1)
            {
                return 1;
            }

            // else, if its not 1, we can check if the version before that is bad

            if (isBadVersion(mid-1))
            {
                // have to search left still
                int currentBadVersion = mid - 1;
                return findBadVersion(0, mid - 1, currentBadVersion);
            }
            
            return mid;
        }

        return findBadVersion(mid + 1, right, currentBadVersion);
    }
};
