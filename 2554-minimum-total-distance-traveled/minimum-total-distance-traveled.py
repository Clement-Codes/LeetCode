class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        robot.sort()
        factory.sort()
        factories = []
        for i in factory:
            factories.extend([i[0]] * i[1])
        
        memo = [[-1 for _ in range(len(factories))] for _ in range(len(robot))]

        def dfs(i, j):
            if i == -1:
                return 0
            if j == -1:
                return float("inf")
            if memo[i][j] != -1: 
                return memo[i][j]
            memo[i][j] = min(abs(factories[j] - robot[i]) + dfs(i - 1, j - 1), dfs(i, j - 1))
            return memo[i][j]

        return dfs(len(robot) - 1, len(factories) -1)
