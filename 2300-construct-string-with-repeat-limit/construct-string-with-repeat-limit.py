class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        c = Counter(s)
        cache = [(-ord(i), j) for i, j in c.items()]
        heapq.heapify(cache)
        result = []
        while cache:
            curr_word, curr_count = heapq.heappop(cache)
            n = min(curr_count, repeatLimit)
            result.append(chr(-curr_word) * n)
            if curr_count - n > 0 and cache:
                next_word, next_count = heapq.heappop(cache)
                result.append(chr(-next_word))
                if next_count > 1:
                    heapq.heappush(cache, (next_word, next_count - 1))
                heapq.heappush(cache, (curr_word, curr_count - n))

        return ''.join(result)