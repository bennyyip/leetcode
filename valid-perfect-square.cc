class Solution {

    int mySqrt(int x) {
        if (x <= 1)
            return x;
        int y = 46340, z;
        while ((z = (y + x / y) >> 1) < y)
            y = z;
        return y;
    }

public:
    bool isPerfectSquare(int num) {
        int root = mySqrt(num);
        return root * root == num;
    }
};
