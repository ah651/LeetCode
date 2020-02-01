class Solution:
    def findRadius(self, houses, heaters) -> int:
        houses.sort()
        heaters.sort()
        if len(houses) == 0:
            return 0 
        result = 0
        pre = 0 
        for h in houses:
            tmp = self.binarySearch(heaters, pre, h)
            # find radius of current house 
            if tmp == 0 and heaters[tmp]-h > result:
                result = heaters[tmp]-h
            elif tmp == -1 and h-heaters[-1] > result:
                result = h-heaters[-1]
            elif tmp != 0 and tmp != -1 and min(heaters[tmp]-h, h-heaters[tmp-1]) > result:
                result = min(heaters[tmp]-h, h-heaters[tmp-1])
            pre = tmp 
        return result 

    def binarySearch(self, arr, lo, target):
        lo, hi = lo, len(arr)-1 
        while lo <= hi:
            mid = (lo + hi) // 2 
            if arr[mid] < target:
                lo = mid + 1 
            elif arr[mid] > target:
                hi = mid - 1 
            else:
                return mid 
        if lo == len(arr):
            return -1 
        else:
            return lo   
