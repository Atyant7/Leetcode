class Solution {
public:
    int maximumLengthSubstring(string s) {
        map<char, int> mp;
        int j = 0;
        int ans = -1;
        for(int i = 0 ; i < s.size() ; i++){
            mp[s[i]]++;
            while(mp[s[i]] > 2){
                mp[s[j]]--;
                j++;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};