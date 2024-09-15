class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        closeToOpen = {"}":"{",")":"(","]":"["}
        for c in s:
            if c in closeToOpen:
                if stack and closeToOpen[c] == stack[-1]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(c)
        print(stack)
        return True if not stack else False