class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        int si = s.length();
        if (s[0] == '1') {
            for (int i = 0; i < si; i += 2) {
                if (s[i] != '1') ans++;
            }
            for(int i = 1 ; i < si ; i+=2){
                if(s[i] != '0') ans++;
            }
        }
        if (s[0] == '0') {
            for (int i = 0; i < si; i += 2) {
                if (s[i] != '0') ans++;
            }
            for(int i = 1 ; i < si ; i+=2){
                if(s[i] != '1') ans++;
            }
        }
        int final_ans = min(ans , int(s.size()) - ans);
        return final_ans;
    }
};