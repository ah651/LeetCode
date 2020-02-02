import random 
import bisect
class Solution:

    def __init__(self, rects: List[List[int]]):
        self.rects = rects 
        self.weights = []
        total_area = 0 
        for rect in rects:
            area = (rect[2] - rect[0] + 1)*(rect[3] - rect[1] + 1)
            total_area += area 
            self.weights.append(total_area-1)
        

    def pick(self) -> List[int]:
        # random select a rect 
        rand_weight = random.randint(0, self.weights[-1])
        rand_rect = bisect.bisect_left(self.weights, rand_weight)
        # random select a point
        return [random.randint(self.rects[rand_rect][0], self.rects[rand_rect][2]), random.randint(self.rects[rand_rect][1], self.rects[rand_rect][3])]


# Your Solution object will be instantiated and called as such:
# obj = Solution(rects)
# param_1 = obj.pick()