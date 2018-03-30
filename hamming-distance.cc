#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
    int hammingDistance(int x, int y) {
        int r = 0;
        REP(i, 32) {
            if ((x & 1) != (y & 1))
                r++;
            x >>= 1;
            y >>= 1;
        }
        return r;
    }
};
