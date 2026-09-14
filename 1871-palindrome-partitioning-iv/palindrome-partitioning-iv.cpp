// Exhaustive Search
// T(n) = 0(n^2 * n), 0(1) extra space
class Solution1 {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        for (int i1 = 1; i1 < n - 1; i1++) {
            for (int i2 = i1 + 1; i2 < n; i2++) {
                if (isPal(s, 0, i1 - 1) && isPal(s, i1, i2 - 1) &&
                    isPal(s, i2, n - 1)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool isPal(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};


class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();

        vector<vector<char>> P(n, vector<char>(n, -1));

        for (int i1 = 1; i1 < n - 1; i1++) {

            if (isPal_rec(s, 0, i1 - 1, P) == false)
                continue;

            for (int i2 = i1 + 1; i2 < n; i2++) {

                if (isPal_rec(s, i1, i2 - 1, P) &&
                    isPal_rec(s, i2, n - 1, P)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isPal_rec(string& s, int i, int j, vector<vector<char>>& p) {

        // Empty or single character
        if (i >= j)
            return true;

        // Already calculated
        if (p[i][j] != -1)
            return p[i][j];

        // Calculate and STORE the answer
        return p[i][j] =
            (s[i] == s[j] && isPal_rec(s, i + 1, j - 1, p));
    }
};