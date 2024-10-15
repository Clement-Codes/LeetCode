class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = defaultdict(int)
        for num in nums:
            counts[num] += 1
        bucket = [[] for i in range(len(nums) + 1)]
        for i, j in counts.items():
            bucket[j].append(i)
        result = []
        for i in range(len(nums), -1, -1):
            if(bucket[i]): result.extend(bucket[i])
            if len(result) == k: break
        return result

















        














        # count = defaultdict(int)
        # for i in nums:
        #     count[i] += 1
        # bucket = [[] for i in range(len(nums) + 1)]
        # for i,v in count.items():
        #     bucket[v].append(i)
        
        # result = []

        # for i in range(len(bucket)-1, 0 , -1):
        #     for j in bucket[i]:
        #         result.append(j)
        #     if len(result) == k:
        #         break
        
        # return result