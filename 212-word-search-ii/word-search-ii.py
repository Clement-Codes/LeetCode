class TrieNode:
    def __init__(self):
        self.children = {}
        self.endOfWord = False
    
    def add(self, word):
        curr = self
        for w in word:
            if w not in curr.children: curr.children[w] = TrieNode()
            curr = curr.children[w]
        curr.endOfWord = True

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = TrieNode()
        for word in words:
            root.add(word)
        result = set()
        visited = set()
        ROW = len(board)
        COL = len(board[0])
        def backtracking(i, j, node, word):
            if (i<0 or j<0 or i==ROW or j==COL or (i, j) in visited or board[i][j] not in node.children): return
            node = node.children[board[i][j]]
            word = word + board[i][j]
            visited.add((i,j))
            if node.endOfWord:
                result.add(word)
            backtracking(i -1 , j , node, word)
            backtracking(i , j - 1, node, word)
            backtracking(i + 1, j, node, word)
            backtracking(i , j + 1, node, word)
            visited.remove((i,j))
        for i in range(0, ROW):
            for j in range(0, COL):
                backtracking(i, j, root, "")
        return result