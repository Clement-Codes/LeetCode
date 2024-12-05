class Solution:
    def canChange(self, start: str, target: str) -> bool:
        i, j = 0, 0
        while i < len(start) and j < len(target):
            if start[i] == target[j] == '_':
                i += 1
                j += 1
            elif start[i] == '_' :
                i += 1
            elif target[j] == '_':
                j += 1
            elif start[i] == target[j] == 'R':
                if i > j:
                    return False
                else:
                    i += 1
                    j += 1
            elif start[i] == target[j] == 'L':
                if i < j:
                    return False
                else:
                    i += 1
                    j += 1
            else:
                return False
        
        while i < len(start) and start[i] == '_' :
                i += 1

        while j < len(target) and target[j] == '_':
                j += 1
        return True if i == len(start) and j == len(target) else False