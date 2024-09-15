class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        stack = []
        cars = [ (i,j) for i, j in zip(position, speed)]
        cars.sort(reverse = True)
        for i in cars:
            print((target-i[0])/i[1])
            stack.append((target-i[0])/i[1])
            if len(stack)>1 and stack[-1]<=stack[-2]:
                stack.pop()
            
        return len(stack)