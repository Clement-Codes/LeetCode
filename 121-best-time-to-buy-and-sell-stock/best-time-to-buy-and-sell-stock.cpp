class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = 0;
        int high = low + 1;
        int profit = 0;
        while(high < prices.size()){
            if(prices[low] < prices[high]) profit = max(profit, prices[high] - prices[low]);
            else low = high;
            high += 1;
        }
        return profit;
    }
};