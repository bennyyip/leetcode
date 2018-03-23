class Solution {
public:
    double myPow(double x, int n) {
        bool neg = n < 0;
        double r = 1;
        if (neg) {
            if (n == INT_MIN) {
                n++;
                r = x;
            }
            n = -n;
        }
        for (; n; n >>= 1, x *= x)
            if (n & 1)
                r *= x;

        return neg ? 1.0 / r : r;
    }
};
