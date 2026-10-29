class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        int ans = INT_MIN;
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++){
            mp.clear();
            for(int j = i; j < n; j++){
                mp[s[j]]++;
                bool flag = true;
                int temp = 0;
                for(auto a : mp){
                    if(a.second < k){
                        flag = false;
                    }
                    temp += a.second;
                }
                if(flag) ans = max(ans, temp);
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};