class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        box = list(map(list, zip(*box[::-1])))
        print(box)
        for c in range(len(box[0])):
            r = len(box) - 1
            while 0 < r:
                while 0 < r and box[r][c] != '.':
                    r -= 1
                l = r - 1
                while 0 < l and box[l][c] == '.':
                    l -= 1
                if box[l][c] == '*':
                    r = l
                elif l >= 0:
                    box[l][c], box[r][c] = box[r][c], box[l][c]
                    l -= 1
                    r -= 1
                else:
                    break
        return box

        # for i in box:
        #     r = len(i) - 1
        #     l = 0
        #     while 0 < r:
        #         while 0 < r and i[r] != '.':
        #             r -= 1
        #         l = r - 1
        #         while i[l] == '.':
        #             l -= 1
        #         if i[l] == '*':
        #             r = l
        #         else:
        #             i[l], i[r] = i[r], i[l]
        #             l -= 1
        #             r -= 1
        # print(box)
        # return list(map(list, zip(*box)))
    #     for i in box:
    #         l = len(i) - 2
    #         r = len(i) - 1
    #         while 0 < l < r:
    #             while l < r and i[r] != '.':
    #                 r -= 1
    #             while
    #             i[l], i[r] = i[r], i[l]
    #             l -= 1
    #             r -= 1
    #     print(box)
    #     return list(map(list, zip(*box)))