class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if t == "" or len(s)<len(t) : return ""

        history, window = {} , {}

        for i in t:
            history[i] = 1 + history.get(i, 0)

        having = 0
        needed = len(history)

        l = 0
        resultIndex, resultLen = [-1, -1], float("infinity")

        for r in range(len(s)):
            c = s[r]
            window[c] = 1 + window.get(c, 0)

            if c in history and window[c] == history.get(c, 0):
                having += 1

            while having == needed:
                if (r -l +1) < resultLen: 
                    resultIndex = [l, r]
                    resultLen = r - l + 1

                c = s[l]
                window[c] -= 1
                if c in history and window[c] < history[c]:
                    having -= 1

                l += 1
        return s[resultIndex[0]:resultIndex[1]+1] if resultLen != float("infinity") else ""

