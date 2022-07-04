class Solution {
public:
    int divide(int dividend, int divisor) {
        int res = 0;
        if (dividend == INT_MIN) {
            if (divisor == -1) return INT_MAX;
            if (divisor == 1) return INT_MIN;
            res = 1;
            dividend += abs(divisor);
        }
        if (divisor == INT_MIN) {
            if (dividend == INT_MIN) return 1;
            else return 0;
        }
        int dvd = abs(dividend), dvs = abs(divisor), sum = 0;
        while (dvd >= dvs) {
            int tmp = dvs, m = 1;
            while (dvd - tmp >= tmp) {
                tmp <<= 1;
                m <<= 1;
            }
            res += m;
            dvd -= tmp;
        }
        return ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) ? -res : res;
    }
