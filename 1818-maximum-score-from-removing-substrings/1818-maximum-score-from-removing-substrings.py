class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        def remove_pair(pair, score):
            nonlocal s
            result = 0
            arr = []
            for i in s:
                if i == pair[1] and arr and arr[-1] == pair[0]:
                    arr.pop()
                    result += score
                else:
                    arr.append(i)
            s = "".join(arr)
            return result
        pair = "ab" if x > y else "ba"
        result = 0
        result += remove_pair(pair, max(x, y))
        result += remove_pair(pair[::-1], min(x, y))
        return result