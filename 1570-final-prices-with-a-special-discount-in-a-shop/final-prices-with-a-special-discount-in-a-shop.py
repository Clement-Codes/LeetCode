class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        n = len(prices)
        deq = deque()
        for l in range(n):
            while len(deq) > 0 and prices[l] <= prices[deq[-1]]:
                r = deq.pop()
                prices[r] -= prices[l]
            deq.append(l)
        return prices

        # kind of two pointers basically for loops i guess
        # n = len(prices)
        # l = 0
        # while l < n:
        #     r = l + 1
        #     while r < n and prices[l] < prices[r]:
        #         r += 1
        #     if r == n:
        #         prices[l] = prices[l]
        #         l += 1
        #     else:
        #         prices[l] = (prices[l] - prices[r])
        #         l, r = l + 1, r + 1
        # return prices
