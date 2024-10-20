class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        i = 0

        def helper():
            nonlocal i
            c = expression[i]
            i += 1
            if c == 't': return True
            if c == 'f': return False
            i += 1
            if c == '!':
                res = not helper()
                i += 1
                return res
                

            elements = []
            while expression[i] != ')':
                if expression[i] != ',':
                    elements.append(helper())
                else:
                    i += 1
            i += 1
            if c == '&':
                return all(elements)
            if c == '|':
                return any(elements)
        return helper()