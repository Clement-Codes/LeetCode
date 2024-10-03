class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices;
        for (int i = 0; i < n; i++) prices.push_back(INT_MAX);

        prices[src] = 0;

        for (int i = 0; i < k+1; i++){
            vector<int> tempPrices;
            tempPrices.assign(prices.begin(), prices.end());
            for (vector<int> flight: flights){
                if (prices[flight[0]] == INT_MAX) continue;
                if (prices[flight[0]] + flight[2] < tempPrices[flight[1]]) tempPrices[flight[1]] = prices[flight[0]] + flight[2];
            }
            prices = tempPrices;
        }

        return prices[dst] == INT_MAX ? -1 :  prices[dst];
    }
};