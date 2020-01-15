class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if matrix == None or len(matrix) == 0 or len(matrix[0]) == 0:
            return False 
        lo, hi = 0, len(matrix)-1 
        while lo <= hi:
            mid = (lo+hi)//2 
            if matrix[mid][0] > target:
                hi = mid - 1
            elif matrix[mid][0] < target:
                lo = mid + 1 
            else:
                return True 

        row = hi 
        lo, hi = 0, len(matrix[0])-1
        while lo <= hi:
            mid = (lo + hi) // 2
            if matrix[row][mid] < target:
                lo = mid + 1 
            elif matrix[row][mid] > target:
                hi = mid - 1
            else:
                return True 
        return False 