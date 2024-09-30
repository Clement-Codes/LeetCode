class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        parent = [i for i in range(len(edges) + 1)]
        rank = [1 for i in range(len(edges) + 1)]

        def find(i):
            res = parent[i]
            while res != parent[res]:
                parent[res] = parent[parent[res]]
                res = parent[res]
            return res
        
        def union(i, j):
            i, j = find(i), find(j)
            if i == j: return False
            if rank[i] >= rank[j]:
                rank[i] += rank[j]
                parent[j] = i
            else:
                rank[j] += rank[i]
                parent[i] = j
            return True
        
        for edge in edges:
            if not union(edge[0], edge[1]): return edge