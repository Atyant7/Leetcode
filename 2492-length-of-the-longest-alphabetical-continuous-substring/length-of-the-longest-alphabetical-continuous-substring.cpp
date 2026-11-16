class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();

        int count = 1;
        int ans = 1;

        for(int i = 1; i < n; i++) {

            if(s[i] == s[i-1] + 1) {
                count++;
            }
            else {
                count = 1;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};