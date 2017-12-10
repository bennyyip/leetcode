class Solution {
public:
    int reverse(int x) {
        long r = 0;
        while (x) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return INT_MIN <= r && r <= INT_MAX ? r : 0;
    }
};
