class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0: return False
        
        cache = {}
        for i in hand:
            cache[i] = cache.get(i, 0) + 1
        
        hand = list(cache.keys())
        heapq.heapify(hand)

        while hand:
           
            minimum = hand[0]
            for i in range(minimum, minimum + groupSize):
                if i not in cache:
                    return False
                
                cache[i] -= 1
                if cache[i] == 0:
                    if i != hand[0]:
                        return False
                    heapq.heappop(hand)
        return True