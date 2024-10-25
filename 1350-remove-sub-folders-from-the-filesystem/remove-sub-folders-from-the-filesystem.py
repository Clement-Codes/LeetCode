class Trie:
    def __init__(self):
        self.children = {}
        self.endOfWord = False
    
    def add(self, word):
        curr = self
        for i in word.split('/'):
            if i not in curr.children:
                curr.children[i] = Trie()
            curr = curr.children[i]
        curr.endOfWord = True

    def prefixSearch(self, word):
        curr = self
        for i in word.split('/')[:-1]:
            curr = curr.children[i]
            if curr.endOfWord:
                return True
        return False

class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        curr = Trie()

        result = []
        for i in folder:
            curr.add(i)
        
        for i in folder:
            if  curr.prefixSearch(i):
                continue
            result.append(i)

        return result


        # cache = Trie()
        # result = []

        # for f in folder:
        #     temp = cache
        #     for d in f[1:].split('/'):
        #         if d not in temp.childrens:
        #             temp.childrens[d] = Trie() 
        #         temp = temp.childrens[d] 
        #     temp.end = True
        
        

        # stack = [(cache, "")]
        # while stack:
        #     temp1, temp2 = stack.pop(0)
        #     if temp1.end:
        #         result.append(temp2)
        #         continue
        #     for i, j in temp1.childrens.items():
        #         stack.append((j, temp2+'/'+i))


            

        # return result

        # cache = set(folder)
        # result = []
        # for i in folder:
        #     result.append(i)
        #     for j in range(len(i)):
        #         if i[j] == "/" and i[:j] in cache:
        #             result.pop()
        #             break
        # return result

