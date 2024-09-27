class TrieNode:
    def __init__(self):
        self.children = {}
        self.endOfWord = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        curr = self.root
        for c in word:
            if not c in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]
        curr.endOfWord = True

    def search(self, word: str) -> bool:
        def backtracking(j, curr):
            for i in range(j, len(word)):
                if word[i] == ".":
                    for child in curr.children.values():
                        if backtracking(i + 1, child):
                            return True
                    return False
                else:
                    if not word[i] in curr.children:
                        return False
                    curr = curr.children[word[i]]
            return curr.endOfWord

        return backtracking(0, self.root)
            


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)