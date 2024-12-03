class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        result = []
        i, j = 0, 0
        while i < len(s) and j < len(spaces):
            if i < spaces[j]:
                result.append(s[i])
                i += 1
            else:
                result.append(' ')
                j += 1
        result.append(s[i:])
        return ''.join(result)
        # result = list(s)
        # for i in spaces:
        #     result.insert(i, " ")
        
        # print(result)

        #8876 
        # for space in reversed(spaces):
        #     s = s[:space] +" "+s[space:]
        # return s