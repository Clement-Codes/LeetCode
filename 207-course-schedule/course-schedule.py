class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        mapper = {}
        visited = set()

        for i in range(numCourses):
            mapper[i] = []

        for i in prerequisites:
            mapper[i[0]].append(i[1])

        def dfs(i):
            if i in visited:
                return False
            if len(mapper[i]) == 0:
                return True
            visited.add(i)
            for j in mapper[i]:
                if not dfs(j):
                    return False
            visited.remove(i)
            mapper[i] = []
            return True

        for i in range(numCourses):
            if dfs(i) == False: 
                return False
        return True
            