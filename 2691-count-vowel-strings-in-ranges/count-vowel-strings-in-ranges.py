class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        prefix = [0] * (len(words) + 1)
        prev = 0
        vowel = set(['a','e','i','o','u'])
        for i, word in enumerate(words):
            if word[0] in vowel and word[-1] in vowel:
                prev += 1
            prefix[i + 1] = prev

        result = [0] * len(queries)

        for i, query in enumerate(queries):
            result[i] = prefix[query[1] + 1] - prefix[query[0]]
        
        return result