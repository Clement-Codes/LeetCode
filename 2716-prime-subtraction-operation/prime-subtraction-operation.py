class Solution:
    def primeSubOperation(self, nums: List[int]) -> bool:
        def isPrime(n):
            for i in range(2, int(sqrt(n)) + 1):
                if n % i == 0:
                    return False
            return True

        prev = 0
        
        for i in range(len(nums)):
            upperbound = nums[i] - prev
            largest_p = 0
            for j in reversed(range(2, upperbound)):
                if isPrime(j):
                    largest_p = j
                    break
            if nums[i] - largest_p <= prev:
                return False       
            prev = nums[i] - largest_p
        return True