class Solution:
    '''
    这种区间问题，既有按区间起点排序更简单的问题，也有按照区间终点排序更简单的问题。
    需要自己思考的时候判断，如果发现一种排序很复杂，就换用另一种排序方式思考。

    贪心的题肯定都能用dp解（贪心不往回看 dp往回看），dp能解的暴力搜索（回溯）也能解。
    思考的时候从后往前思考更容易。

    数组问题优先思考dp，贪心。
    一个一维数组用dp通常只需要一维dp表 表示到当前坐标为止最大（小）
    '''
    def eraseOverlapIntervals(self, intervals) -> int:
        if len(intervals) <= 1:
            return 0
        intervals.sort(key=lambda i: i[0])
        i = 1
        pre = 0
        cnt = 0
        while i < len(intervals):
            if intervals[i][1] <= intervals[pre][1]:
                cnt += 1
                pre = i 
            elif intervals[i][0] >= intervals[pre][1]:
                pre = i 
            else:
                cnt += 1
            i += 1
        return cnt 