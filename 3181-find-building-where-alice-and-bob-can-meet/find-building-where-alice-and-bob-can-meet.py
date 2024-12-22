class Solution:
    def leftmostBuildingQueries(self, heights: List[int], queries: List[List[int]]) -> List[int]:
        n = len(queries)
        result = [-1] * n
        grouped = defaultdict(list)
        
        for i, query in enumerate(queries):
            l, r = sorted(query)
            if l == r or heights[r] > heights[l]:
                result[i] = r
            else:
                grouped[r].append((heights[l], i))
        
        heap = []
        for i, h in enumerate(heights):
            for j in grouped[i]:
                heapq.heappush(heap, j)
            while heap and h > heap[0][0]:
                temp = heapq.heappop(heap)
                result[temp[1]] = i 
        return result




        # result = []
        # n = len(heights)
        # adj = defaultdict(list)
        
        # for i in queries:
        #     for j in range(i[0] + 1, n):
        #         if heights[i[0]] < heights[j]:
        #             adj[i[0]].append(j)
        

        # for query in queries:
        #     left = adj[query[0]]
        #     right = adj[query[1]]
        #     inter = list(set(left).intersection(right))
        #     result.append(inter[0] if len(inter) > 0 else -1)
        # return result
        # result = []
        # n = len(heights)
        # adj = defaultdict(int)
        
        # for i in range(n):
        #     for j in range(i + 1, n):
        #         if heights[i] < heights[j]:
        #             adj[i] = j
        #             break
        
        # for query in queries:
        #     l = query[0]
        #     r = query[1]
        #     while l != r:
        #         if l not in adj:
        #             break
        #         if r not in adj:
        #             break
        #         l = adj[l]
        #         r = adj[r]
        #     result.append(l if l == r else -1)
        # return result

        # using adj memory limit
        # result = []
        # n = len(heights)
        # adj = defaultdict(list)
        
        # for i in range(n):
        #     adj[i].append(i)
        #     for j in range(i + 1, n):
        #         if heights[i] < heights[j]:
        #             adj[i].append(j)
        

        # for query in queries:
        #     left = adj[query[0]]
        #     right = adj[query[1]]
        #     inter = list(set(left).intersection(right))
        #     result.append(inter[0] if len(inter) > 0 else -1)
        # return result

        # brute force
        # n = len(heights)
        # for query in queries:
        #     l = query[0]
        #     r = query[1]
        #     while l != r and l < n and r < n:
        #         if l < r:
        #             temp = l + 1
        #             while temp < n - 1 and heights[query[0]] >= heights[temp] :
        #                 temp += 1
        #             if heights[query[0]] >= heights[temp]:
        #                 break
        #             l = temp
        #         else:
        #             temp = r + 1
        #             while temp < n - 1 and  heights[query[1]] >= heights[temp]:
        #                 temp += 1
        #             if heights[query[1]] >= heights[temp]:
        #                 break
        #             r = temp
        #     if l == r and l < n:
        #         result.append(l)
        #     else:
        #         result.append(-1)
        # return result