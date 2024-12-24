class Solution:
    def minimumDiameterAfterMerge(self, edges1: List[List[int]], edges2: List[List[int]]) -> int:

        def getAdjacent(edges):
            adj = defaultdict(list)
            for i, j in edges:
                adj[i].append(j)
                adj[j].append(i)
            return adj

        adj1 = getAdjacent(edges1)
        adj2 = getAdjacent(edges2)

        def dfs(curr, parent, adj):
            diameter = 0
            childrens = [0, 0]
            for node in adj[curr]:
                if node == parent:
                    continue
                node_diameter, node_childrens = dfs(node, curr, adj)
                diameter = max(diameter, node_diameter)
                heappush(childrens, node_childrens)
                heappop(childrens)
            diameter = max(diameter, sum(childrens))
            return [diameter, 1+max(childrens)]
        
        d1, _ = dfs(0, -1, adj1)
        d2, _ = dfs(0, -1, adj2)
        return max(d1, d2, 1 + ceil(d1/2) + ceil(d2/2))
