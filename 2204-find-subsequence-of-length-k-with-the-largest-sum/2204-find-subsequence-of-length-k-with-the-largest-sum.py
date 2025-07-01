class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        preserve_position = [[j,i] for i,j in enumerate(nums)]
        preserve_position.sort(key=lambda x: -x[0])
        preserve_position = preserve_position[:k]
        preserve_position.sort(key=lambda x: x[1])
        return([ i for i,j in preserve_position])

