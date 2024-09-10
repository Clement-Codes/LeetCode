class Solution:
    def romanToInt(self, s: str) -> int:
        result = 0
        i = 0
        while len(s):
            skip = 1
            if s[0] == 'M':
                result += 1000
            elif s[0] == 'D':
                result += 500
            elif s[0] == 'C':
                if len(s) > 1 and s[1] == 'D':
                    result += 400
                    skip+=1
                elif len(s) > 1 and s[1] == 'M':
                    result += 900
                    skip += 1
                else:
                    result += 100
            elif s[0] == 'L':
                result += 50
            elif s[0] == 'X':
                if len(s) > 1 and s[1] == 'L':
                    result += 40
                    skip += 1
                elif len(s) > 1 and s[1] == 'C':
                    result += 90
                    skip += 1
                else:
                    result += 10
            elif s[0] == 'V':
                result += 5
            elif s[0] == 'I':
                if len(s) > 1 and s[1] == 'V':
                    result += 4
                    skip += 1
                elif len(s) > 1 and s[1] == 'X':
                    result += 9
                    skip += 1
                else:
                    result += 1
            s = s[skip:]
        return result
