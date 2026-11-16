class Solution {
public:
    int helper(string &s, int i, int count) {
        if (i == s.size()) {
            return count;
        }

        if (s[i] == s[i-1] + 1) {
            return helper(s, i + 1, count + 1);
        }

        int ans = max(count, helper(s, i + 1, 1));

        return ans;
    }

    int longestContinuousSubstring(string s) {
        return helper(s, 1, 1);
    }
};