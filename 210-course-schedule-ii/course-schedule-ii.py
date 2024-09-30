class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:

        mapper = {c: [] for c in range(numCourses)}

        for c, r in prerequisites:
            mapper[c].append(r)
        
        result = []
        visited, cycle = set(), set()

        def dfs(i):
            if i in cycle:
                return False
            if i in visited:
                return True
            
            cycle.add(i)
            for c in mapper[i]:
                if not dfs(c):
                    return False
            cycle.remove(i)
            visited.add(i)
            result.append(i)
            return True

        for c in range(numCourses):
            if not dfs(c): return []
        return result