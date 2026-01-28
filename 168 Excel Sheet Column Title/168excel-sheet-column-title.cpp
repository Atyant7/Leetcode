class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s = "";

        while (columnNumber > 0) {
            columnNumber--; // shift to 0-based
            char ch = (columnNumber % 26) + 'A';
            s += ch;
            columnNumber /= 26;
        }

        reverse(s.begin(), s.end());
        return s;
    }
};