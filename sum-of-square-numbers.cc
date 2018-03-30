class Solution {

public:
    bool judgeSquareSum(int c) {
        int n = sqrt(c);
        int l = 0, r = n;

        while (l <= r) {
            int t = l * l + r * r;
            if (t > c)
                r--;
            else if (t < c)
                l++;
            else
                return true;
        }
        return false;
    }
};
