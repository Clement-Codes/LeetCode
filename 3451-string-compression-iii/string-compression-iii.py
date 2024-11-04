class Solution:
    # def handler(self, t):
    #     j, i = t
    #     temp = ""
    #     while j / 9 > 1:
    #         j -= 9
    #         temp += "9" + i
    #     temp += str(j) + i
    #     return temp
        
        

    def compressedString(self, word: str) -> str:
        consec, curr, result = 1, word[0], ''

        for i in range(1, len(word)):
            if curr == word[i] and consec < 9:
                consec += 1
            else:
                result += f'{consec}{curr}'
                consec = 1
                curr = word[i]
        result += f'{consec}{curr}'
        return result
        # cache =  defaultdict(int)
        # for i in word:
        #     cache[i] += 1

        # heap = []
        # for i, j in cache.items():
        #     heapq.heappush(heap, (j, i))

        # result = ""
        # while heap:
        #     result += self.handler(heapq.heappop(heap))
        # return result