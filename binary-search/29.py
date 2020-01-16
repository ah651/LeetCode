class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend == -2**31 and divisor == -1:
            return 2**31 - 1
        quotient = 0
        dividend_a = dividend if dividend >= 0 else -dividend
        divisor_a = divisor if divisor >= 0 else -divisor
        quotient = self.divide2(dividend_a, divisor_a)
        # while dividend_a >= divisor_a:
        #     dividend_a -= divisor_a
        #     quotient += 1
        if (dividend >= 0 and divisor > 0) or (dividend <= 0 and divisor < 0):
            return quotient 
        else:
            return -quotient 

    def divide2(self, dividend, divisor):
        if dividend < divisor:
            return 0 
        quotient = 1
        origin_divisor = divisor 
        while dividend >= divisor:
            dividend -= divisor
            quotient += quotient
            divisor += divisor

        return quotient-1 + self.divide2(dividend, origin_divisor)
        