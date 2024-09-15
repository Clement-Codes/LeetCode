class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        stack = []
        result = []

        def backTracking(openBrackets, closeBrackets):
            if openBrackets == closeBrackets == n:
                result.append(''.join(stack))
            if openBrackets < n:
                stack.append('(')
                backTracking(openBrackets + 1, closeBrackets)
                stack.pop()
            if closeBrackets < openBrackets:
                stack.append(')')
                backTracking(openBrackets, closeBrackets + 1)
                stack.pop()
        
        backTracking(0, 0)
        return result