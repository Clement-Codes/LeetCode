from collections import Counter

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        task = [-i for i in Counter(tasks).values()]
        heapq.heapify(task)
        queue = deque()
        t = 0
        while task or queue:
            t += 1
            if task:
                curr = 1 + heapq.heappop(task)
                if curr:
                    queue.append([curr, t+n])
            if queue and queue[0][1] == t:                
                heapq.heappush(task, queue.popleft()[0])
        return t