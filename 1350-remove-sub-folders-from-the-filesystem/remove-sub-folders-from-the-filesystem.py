class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        cache = set(folder)
        result = []
        for i in folder:
            result.append(i)
            for j in range(len(i)):
                if i[j] == "/" and i[:j] in cache:
                    result.pop()
                    break
        return result

