class Solution {
public:
    int divide(int p, int q) {
        if (!q || p == INT_MIN && q == -1)
            return INT_MAX;
        int r = 0;
        int sign = ((p < 0) ^ (q < 0)) ? -1 : 1;
        long long pp = labs(p);
        long long qq = labs(q);

        while (pp >= qq) {
            long long tmp = qq, mul = 1;
            while (pp >= (tmp << 1)) {
                tmp <<= 1;
                mul <<= 1;
            }
            pp -= tmp;
            r += mul;
        }
        return sign == 1 ? r : -r;
    }
};
