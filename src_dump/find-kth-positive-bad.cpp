class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missing;

        int counter = 1;
        int pointer = 0;

        while (pointer < arr.size())
        {
            if (counter < arr[pointer])
            {
                missing.push_back(counter);
                counter++;
            }
            else
            {
                pointer++;
                counter++;
            }
        }

        if (missing.size() == 0)
        {
            return arr[arr.size() - 1] + k;
        }

        if (missing.size() < k)
        {
            int addCounter = k - missing.size();
            int nrToAdd = arr[arr.size() - 1] + 1;
            while (addCounter >= 0)
            {
                missing.push_back(nrToAdd);
                nrToAdd++;
                addCounter--;
            }
        }

        return missing[k - 1];
    }
};
