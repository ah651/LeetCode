class Solution:
    def findMinArrowShots(self, points) -> int:
        if len(points) == 0:
            return 0
        points.sort(key=lambda p:p[1])
        i = 0
        cnt = 0
        while i < len(points):
            end = points[i][1]
            cnt += 1
            # while i < len(points) and points[i][0] == start:
            #     if points[i][1] < end:
            #         end = points[i][1]
            #     i += 1

            while i < len(points) and points[i][0] <= end:
                i += 1 

        return cnt             