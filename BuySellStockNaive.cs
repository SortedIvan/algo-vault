public class Solution {
    public int MaxProfit(int[] prices) {

        if (prices.Length == 0) {
            return 0;
        }
        
        int currProfit = 0;
        int bestProfit = 0;

        for (int i = 0; i < prices.Length; i++) {
            for (int k = i + 1; k < prices.Length; k++) {
                if (prices[i] >= prices[k]) { // No need to calculate profits here,
                    break;
                }
                
                if (currProfit < prices[k] - prices[i]) {
                    currProfit = prices[k] - prices[i];
                }
            }

            if (currProfit > bestProfit) {
                bestProfit = currProfit;
            }
        }

        return bestProfit;

    }
}
