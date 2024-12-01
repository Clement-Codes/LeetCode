class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        visited = set()

        for i in arr:
            if 2 * i in visited or (i % 2 == 0 and i // 2 in visited):
                return True
            visited.add(i)


        return False
