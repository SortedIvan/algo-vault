class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int numberNeeded = tickets[k];
        int timeTaken = 0;
        int peopleToRemove = 0;

        for (int i = 0; i < tickets.size(); ++i) {
            if (tickets[i] >= numberNeeded) {                
                if (i > k) {
                    peopleToRemove++;
                }
                timeTaken += numberNeeded;
            } else {
                timeTaken += tickets[i];
            }
        }

        return timeTaken - peopleToRemove;
    }
};
