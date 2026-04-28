class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int profit = 0, buyIdx = 0, sellIdx = 1;
        while (sellIdx < prices.size()) {
            if (prices[buyIdx] > prices[sellIdx]) {
                buyIdx = sellIdx;
            } else {
                profit = max(profit, prices[sellIdx] - prices[buyIdx]);
            }
            sellIdx++;
        }

        return profit;
    }
};
