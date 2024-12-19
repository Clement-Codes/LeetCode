class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        m = -1
        result = 0
        for i, j in enumerate(arr):
            m = max(m, j)
            if i == m:
                result += 1
        return result

        # mono = deque()
        # result = []
        # for i in arr:
        #     while mono and mono[-1] != i + 1:
        #         result.append(mono)
        #         mono.clear()
        #     mono.append(i)
        # result.append(mono)
        # return len(result)
    # def isSorted(self, arr: List[int]) -> bool:
    #     for r in range(len(arr) - 1):
    #         if arr[r] > arr[r + 1]:
    #             return False
    #     return True

    # def maxChunksToSorted(self, arr: List[int]) -> int:
    #     currIter = 0
    #     while not self.isSorted(arr):
    #         for i in range(len(arr) - 1):
    #             if arr[i] > arr[i + 1]:
    #                 arr[i], arr[i + 1] = arr[i + 1], arr[i]
    #         currIter += 1
    #     return len(arr) - currIter