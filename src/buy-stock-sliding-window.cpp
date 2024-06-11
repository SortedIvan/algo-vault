#include <stack>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        unsigned int leftPointer = 0;
        unsigned int rightPointer = 1;
        unsigned int profit = 0;

        while (rightPointer < prices.size())
        {
            if (prices[rightPointer] < prices[leftPointer])
            {
                leftPointer = rightPointer;
                rightPointer++;
            }
            else {
                if ( prices[rightPointer] - prices[leftPointer] > 0)
                {
                    if (profit <  prices[rightPointer] - prices[leftPointer])
                    {
                        profit =  prices[rightPointer] - prices[leftPointer];
                    }
                }

                rightPointer++;
            }
        }
        return profit;
    }
};
