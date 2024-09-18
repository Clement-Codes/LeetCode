class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        A, B = nums1, nums2
        if len(A) > len(B):
            A, B = B, A

        al = 0
        ar = len(A) - 1
        
        while True:
            am = al + ((ar - al) // 2)
            bm = (len(A) + len(B))//2 - am - 2

            AL = A[am] if am >= 0 else float("-infinity")
            AR = A[am + 1] if (am + 1)<len(A) else float("infinity")

            BL = B[bm] if bm >= 0 else float("-infinity")
            BR = B[bm + 1] if (bm + 1)<len(B) else float("infinity")

            if AL <= BR and BL <= AR:
                if (len(A) + len(B)) % 2: return min(AR, BR)
                else: return (max(AL, BL) + min(AR, BR))/2
            elif AL < BR: al = am + 1
            else: ar = am - 1