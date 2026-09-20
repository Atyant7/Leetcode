class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for(int i = 0; i < s.size() ; i++){
            ans += ((s[i] - 71) - (s[i] - 'a')*2) * (i+1);
        }
        return ans;
    }
};