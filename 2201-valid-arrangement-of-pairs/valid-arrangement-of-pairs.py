class Solution:
    
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        adjencyMatrix = collections.defaultdict(list)
        inDegree, outDegree = collections.defaultdict(int), collections.defaultdict(int)

        for s, e in pairs:
            adjencyMatrix[s].append(e)
            outDegree[s] += 1
            inDegree[e] += 1
        
        startNode = -1
        for n in outDegree:
            if outDegree[n] == inDegree[n] + 1:
                startNode = n
                break

        if startNode  == -1:
            startNode = pairs[0][0]
        
        nodeStack = [startNode]
        result = []
        while nodeStack:
            node = nodeStack[-1]
            if adjencyMatrix[node]:
                nextNode = adjencyMatrix[node].pop(0)
                nodeStack.append(nextNode)
            else:
                result.append(node)
                nodeStack.pop()
        result.reverse()

        pairedResult = []
        for i in range(1, len(result)):
            pairedResult.append([result[i-1], result[i]])
        
        return pairedResult
    