class Solution {
public:
    bool isNumber(string s) {
        int len = s.size();
        int i = 0;
        while (i < len && isspace(s[i]))
            i++;
        if (i < len && s[i] == '+' || s[i] == '-')
            i++;

        if (!isdigit(s[i]) && s[i] != '.')
            return false;

        while (i < len && isdigit(s[i]))
            i++;

        if (i < len && s[i] == '.') {
            i++;
	    // if there is no digit surrounding '.', i.e.
	    // ok: 2.
	    // ok: .2
	    // no: .
            if (!isdigit(s[i - 2]) && !isdigit(s[i]))
                return false;
            while (i < len && isdigit(s[i]))
                i++;
        }

        if (i < len && s[i] == 'e' || s[i] == 'E') {
            i++;
            if (i < len && s[i] == '+' || s[i] == '-')
                i++;
            if (!isdigit(s[i]))
                return false;
            while (i < len && isdigit(s[i]))
                i++;
        }

        while (i < len && isspace(s[i]))
            i++;
        return i == len;
    }
};
