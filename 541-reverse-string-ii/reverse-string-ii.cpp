class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();

        int start = 0;

        while (start < n) {
            int end = min(start + k - 1, n - 1);

            int l = start;
            int r = end;

            while (l < r) {
                swap(s[l], s[r]);
                l++;
                r--;
            }

            start += 2 * k;
        }

        return s;
    }
};