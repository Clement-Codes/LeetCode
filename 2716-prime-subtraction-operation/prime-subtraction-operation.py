class Solution:
    def primeSubOperation(self, nums: List[int]) -> bool:
        def isPrime(n):
            for i in range(2, int(sqrt(n)) + 1):
                if n % i == 0:
                    return False
            return True

        prev = 0
        primes = [0, 0]
        for i in range(2, max(nums)):
            if isPrime(i):
                primes.append(i)
            else:
                primes.append(primes[-1])

        for i in range(len(nums)):
            upperbound = nums[i] - prev
            largest_p = primes[upperbound - 1]
            if nums[i] - largest_p <= prev:
                return False       
            prev = nums[i] - largest_p
        return True