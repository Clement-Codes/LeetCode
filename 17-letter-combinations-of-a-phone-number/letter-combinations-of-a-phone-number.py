class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        numberToLetter = {
        '2':['a','b','c'],
        '3':['d','e','f'],
        '4':['g','h','i'],
        '5':['j','k','l'],
        '6':['m','n','o'],
        '7':['p','q','r','s'],
        '8':['t','u','v'],
        '9':['w','x','y','z']
        }
        result = []

        def backtracking(index, curr):
            if len(curr) == len(digits):
                result.append(curr)
                return
            for i in numberToLetter[digits[index]]:
                backtracking(index + 1, curr + i)
        
        if digits:
            backtracking(0,"")
        return result