class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenE = false;
        bool digitAfterE = true; // initially true (no e seen yet)

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                seenDigit = true;
                digitAfterE = true;
            }
            else if (c == '+' || c == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else if (c == '.') {
                if (seenDot || seenE) return false;
                seenDot = true;
            }
            else if (c == 'e' || c == 'E') {
                if (!seenDigit || seenE) return false;
                seenE = true;
                digitAfterE = false;
            }
            else {
                return false;
            }
        }
        return seenDigit && digitAfterE;
    }
};
