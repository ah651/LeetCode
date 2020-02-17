import queue
class Solution:
    def isPossible(self, target) -> bool:
        if len(target) == 0:
            return False 
       
        result_sum = len(target)
        t_sum = 0
        t_max = 0
        t_min = 1
        for i in range(len(target)):
            t_sum += target[i]
            if target[i] > target[t_max]:
                t_max = i

        while True:
            if target[t_max] == 1 and t_sum == result_sum:
                return True 
            if t_min <= 0:
                return False 
            new_value = target[t_max] - (t_sum - target[t_max])
            target[t_max] = new_value
            t_sum = 0
            t_max = 0
            for i in range(len(target)):
                t_sum += target[i]
                if target[i] > target[t_max]:
                    t_max = i
                if target[i] < t_min:
                    t_min = target[i]
    
