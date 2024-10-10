class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if "0" in [num1, num2]: return "0"
        result = [0] * (len(num1) + len(num2))
        num1 = num1[::-1]
        num2 = num2[::-1]
        for i in range(len(num1)):
            for j in range(len(num2)):
                result[i + j] += int(num1[i]) * int(num2[j])
                result[i + j + 1] += result[i + j] // 10
                result[i  + j] = result[i + j] % 10
        result.reverse()
        begin = 0
        for i in range(len(result)):
            if result[i] != 0:
                break
            begin += 1
        result = map(str, result[begin:])
        return ''.join(result)