class Solution {
public:
    int helper(string &s, int i, char ch) {
        if (i == s.size()) {
            return 0;
        }

        if (s[i] != ch) {
            return 0;
        }

        return 1 + helper(s, i + 1, ch + 1);
    }

    int longestContinuousSubstring(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            ans = max(ans, helper(s, i, s[i]));
        }

        return ans;
    }
};