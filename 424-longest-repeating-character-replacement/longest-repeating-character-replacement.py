class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        dictionary = {}
        mostFrequent = 0
        l = 0
        result = 0
        for r in range(len(s)):
            dictionary[s[r]] = 1 + dictionary.get(s[r], 0)
            mostFrequent = max(mostFrequent, dictionary[s[r]])
            while (r - l + 1) - mostFrequent > k:
                dictionary[s[l]] -=1
                l += 1
            print(l, r)
            result = max(result, r - l + 1)
        print(dictionary, r, l)
        return result
