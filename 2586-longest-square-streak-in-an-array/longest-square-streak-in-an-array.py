class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        nums = set(nums)
        res = -1
        for i in nums:
            if sqrt(i) in nums:
                continue
            else:
                j = 1
                while i * i  in nums:
                    j += 1
                    i *= i
                res = max(res, j)

        return res if res > 1 else - 1
        # Sorting 0(nlog(n))
        # nums.sort()
        # res = -1
        # memo = defaultdict(int)
        # for i in nums:
        #     memo[i] = memo[sqrt(i)] + 1

        #     res = max(res, memo[i])
        # return res if res > 1 else - 1



        # result = -1
        # memo = {}
        # nums.sort()
        # for i in nums:
        #     for j in memo.keys():
        #         if isinstance(math.log(i, j), int):
        #             memo[j].append(i)
        #     else:
        #         memo[i] = [i]
        # print(memo)
        # return result
        #brute force
        nums.sort()
        visited = set()
        result = -1
        for i in nums:
            if i in visited: continue
            temp = i
            visited.add(temp)
            temp_result = 1
            while temp ** 2 in nums:
                temp = temp ** 2
                visited.add(temp)
                temp_result += 1
            if temp_result > 1:
                result = max(result, temp_result)
        return result