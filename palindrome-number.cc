class Solution {
public:
    bool isPalindrome(int x) {
        // quick path, still works with out it.
        if (x < 0)
            return false;
        int ten = 1;
        while (x / ten >= 10)
            ten *= 10;
        while (x) {
            if (x / ten != x % 10)
                return false;
            x = x % ten / 10;
            ten /= 100;
        }
        return true;
    }
};
