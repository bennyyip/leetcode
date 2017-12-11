class Solution {
public:
    int romanToInt(string s) {
        int dic[26];
        dic['I' - 'A'] = 1;
        dic['V' - 'A'] = 5;
        dic['X' - 'A'] = 10;
        dic['L' - 'A'] = 50;
        dic['C' - 'A'] = 100;
        dic['D' - 'A'] = 500;
        dic['M' - 'A'] = 1000;

        int r = 0;
        int prev = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            int cur = dic[s[i] - 'A'];
            r += (prev > cur) ? -cur : cur;
            prev = cur;
        }
        return r;
    }
};
