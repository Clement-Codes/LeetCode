class Solution:
    def checkValidCuts(self, n: int, rectangles: List[List[int]]) -> bool:
        X = [[x[0], x[2]] for x in rectangles]
        Y = [[y[1], y[3]] for y in rectangles]

        X.sort()
        Y.sort()

        def count_intersection(x):
            count = 0
            prev_end = -1
            for start, end in x:
                if prev_end <= start:
                    count +=1
                prev_end = max(prev_end, end)
            return count

        return max(count_intersection(X), count_intersection(Y))>=3
