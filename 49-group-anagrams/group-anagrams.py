from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        cache = defaultdict(list)
        for str in strs:
            temp = [0] * 26
            for i in str:
                temp[ord(i) - ord('a')] += 1
            cache[tuple(temp)].append(str)
        return cache.values()














        # result = defaultdict(list)
        # for s in strs:
        #     count = [0] * 26
        #     for i in s:
        #         count[ord(i) - ord('a')] += 1
        #     result[tuple(count)].append(s)
        # return result.values()
        
        