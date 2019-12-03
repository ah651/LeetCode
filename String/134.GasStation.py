class Solution:
    def canCompleteCircuit(self, gas, cost) -> int:

        real_gas = [gas[i]-cost[i] for i in range(len(gas))]

        i = 0
        while i < len(gas):
            if real_gas[i] >= 0:
                tmp_remainder = 0
                for j in range(i, i+len(gas)):
                    tmp_remainder += real_gas[j%len(gas)]
                    if tmp_remainder < 0:
                        if j < i:
                            return -1 
                        else:
                            i = j 
                        break
                if tmp_remainder >= 0:
                    return i 
            else:    
                i += 1

        return -1