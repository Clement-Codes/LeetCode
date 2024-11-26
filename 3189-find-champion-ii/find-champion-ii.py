class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        countParents = [0] * n
        for edge in edges:
            countParents[edge[1]] += 1
        
        champions = []
        for i, c in enumerate(countParents):
            if not c:
                champions.append(i)

        if len(champions) > 1:
            return -1
        return champions[0]