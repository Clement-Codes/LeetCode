class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList: return 0
        
        mapper = defaultdict(list)
        wordList.append(beginWord)
        for word in wordList:
            for i in range(len(word)):
                mapper[word[:i] + "*" + word[i+1:]].append(word)
        
        q = deque([beginWord])
        visited = set([beginWord])
        r = 1
        while q:
            for _ in range(len(q)):
                temp = q.popleft()
                if temp == endWord: return r
                for i in range(len(temp)):
                    for new in mapper[temp[:i] + "*" + temp[i+1:]]:
                        if new not in visited:
                            q.append(new)
                            visited.add(new)
            r += 1
        return 0