class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        elif n < 0:
            return self.fast_pow(1/x, -n)
        else:
            return self.fast_pow(x, n)

    def fast_pow(self, x, n):
        if n == 1:
            return x 
        half = self.fast_pow(x, n//2)
        if n % 2 == 0:
            return half * half 
        else:
            return half * half * x 