class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        price = [float("inf")] * n
        price[src] = 0
        for _ in range(k + 1):
            tempPrice = price.copy()
            for s, d, p in flights:
                if price[s] == float("inf"): continue
                if price[s] + p < tempPrice[d]:
                    tempPrice[d] = price[s] + p
            price = tempPrice.copy()
        
        return -1 if price[dst] == float("inf") else price[dst]