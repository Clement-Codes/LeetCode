class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        mapper = {a: [] for a, b in tickets}
        for i, j in tickets:
            mapper[i].append(j)
        
        for k in mapper:
            mapper[k].sort()

        
        result = []
        
        def dfs(m, node):
            if node in m:
                temp = m[node][:]
                while temp:
                    t = temp[0]
                    m[node].pop(0)
                    dfs(m, t)
                    temp = m[node][:]
            result.append(node)

        dfs(mapper, "JFK")
        
        result.reverse()

        return result if len(result) == (len(tickets) + 1) else []