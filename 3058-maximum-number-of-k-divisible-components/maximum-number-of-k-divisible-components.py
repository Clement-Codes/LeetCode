class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        adjMatrix = defaultdict(list)
        for i, j in edges:
            adjMatrix[i].append(j)
            adjMatrix[j].append(i)
        print(adjMatrix)
        result = 0

        def dfs(curr, parent):
            nonlocal result
            total = values[curr]

            for node in adjMatrix[curr]:
                if node != parent:
                    total += dfs(node, curr)

            if total % k == 0:
                result += 1

            return total
        
        dfs(0, -1)
        return result