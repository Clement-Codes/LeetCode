class Solution:
    def maxDiff(self, num: int) -> int:
        maxi = num
        mini = num
        s = str(num)
        for i in s:
            if i != '9':
                maxi = s.replace(i,'9')
                break
        for i, j in enumerate(s):
            if i == 0 and j != '1':
                mini = s.replace(j,'1')
                break
            elif i > 0 and s[0] != s[i] and j != '0' and int(s.replace(j, '0')) !=0:
                mini = s.replace(j, '0')
                break
        return int(maxi) - int(mini)
