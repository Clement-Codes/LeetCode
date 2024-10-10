class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits.reverse()
        add, i = 1,  0
        while add > 0:
            if i < len(digits):
                if digits[i] == 9:
                    digits[i] = 0
                else:
                    add = 0
                    digits[i] += 1
            else:
                digits.append(1)
                add = 0
            i += 1
        digits.reverse()
        return digits