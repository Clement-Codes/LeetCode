class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        items.sort()
        queries = sorted([(j, i) for i, j in enumerate(queries)])
        result = [0] * len(queries)
        max_curr = 0
        j = 0
        for q, i in queries:
            while j < len(items) and q >= items[j][0]:
                max_curr = max(max_curr, items[j][1])
                j += 1
            result[i] = max_curr
        return result
        # cache = defaultdict(int)
        # for i, j in items:
        #     cache[i] = max(cache[i], j)
        
        # keys = sorted(cache.keys())
        # curr_max = float("-inf")
        # for i in keys:
        #     if cache[i] > curr_max:
        #         curr_max = cache[i]
        #     else:
        #         cache[i] = curr_max

        # result = []
        # for i in queries:
        #     curr_index = 0
        #     while 


        # return result