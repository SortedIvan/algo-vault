public class Solution {
    public int MaxProfit(int[] prices) {

        if (prices.Length == 0 || prices.Length == 1) {
            return 0;
        }
        
        int profit = 0;
        int buy = prices[0];

        for (int i = 1; i < prices.Length; i++) {
            if (buy < prices[i]) {
                int tempProfit = prices[i] - buy;
                if (profit < tempProfit) {
                    profit = tempProfit;
                }
            }
            else {
                buy = prices[i];
            }
        }
        return profit;
    }
}
