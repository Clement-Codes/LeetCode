class Solution:
    def minMaxDifference(self, num: int) -> int:
        s = str(num)
        maxi = s
        for i in s:
            if i != '9':
                maxi = s.replace(i, '9')
                break
        mini = s.replace(s[0],'0')
        return int(maxi) - int(mini)