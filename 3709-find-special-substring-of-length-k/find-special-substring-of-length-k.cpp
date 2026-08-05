class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.size();
        if (k > n)
            return false;
        for (int i = 0; i <= n - k; i++) {
            bool same = true;
            for (int j = i + 1; j < i + k; j++) {
                if (s[j] != s[i]) {
                    same = false;
                    break;
                }
            }
            if (!same)
                continue;
            bool left = (i == 0 || s[i - 1] != s[i]);
            bool right = (i + k == n || s[i + k] != s[i]);
            if (left && right)
                return true;
        }
        return false;
    }
};