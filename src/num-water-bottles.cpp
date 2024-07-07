class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int numberOfFullBottles = numBottles;
        int numberOfEmptyBottles = 0;
        int totalDrank = 0;

        while (true) {
            totalDrank += numberOfFullBottles;
            numberOfEmptyBottles += numberOfFullBottles;
            numberOfFullBottles = 0;    

            if (numberOfEmptyBottles < numExchange) {
                break;
            }

            int remainder = numberOfEmptyBottles % numExchange;
            int exchanged = numberOfEmptyBottles / numExchange;

            numberOfEmptyBottles = remainder;
            numberOfFullBottles = exchanged;
        }

        return totalDrank;
    }
};
