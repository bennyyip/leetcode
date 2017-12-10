class Solution {
public:
    int myAtoi(string str) {
        bool neg = false;
        int r = 0, i = 0;
        int len = str.size();

        while (i < len && isspace(str[i]))
            i++;
        if (i >= len)
            return r;

        if (str[i] == '+')
            i++;
        else if (str[i] == '-')
            neg = true, i++;

        for (; i < len && isdigit(str[i]); ++i) {
            int d = str[i] - '0';
            if (neg) {
                if (r < (INT_MIN + d) / 10)
                    return INT_MIN;
                r = r * 10 - d;
            } else {
                if (r > (INT_MAX - d) / 10)
                    return INT_MAX;
                r = r * 10 + d;
            }
        }
        return r;
    }
};
