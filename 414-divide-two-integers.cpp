// LintCode problem
// If overflow, return INT_MAX;

class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        // Write your code here
        if (divisor == 0)
            return INT_MAX;

        int res = 0;
        if (dividend == INT_MIN) {
            // Negative min abs is 1 higher than 
            // Positive max, causing overflow.
            if (divisor == -1)
                return INT_MAX;
            dividend += abs(divisor);
            // res absolute value should add one.
            res = 1;
        }

        if (divisor == INT_MIN)
            return res;

        // This is more clear and consistent than bit operation.
        bool isNeg = ((dividend >= 0) != (divisor > 0));

        dividend = abs(dividend);
        divisor = abs(divisor);

        int digit = 0;
        while ( divisor <= (dividend>>1)) {
            divisor <<= 1;
            digit++;
        }

        while (digit >= 0) {
            if (dividend >= divisor) {
                dividend -= divisor;
                res += 1<<digit;
            }
            divisor >>= 1;
            digit--;
        }

        return isNeg ? -res : res;
    }
};

