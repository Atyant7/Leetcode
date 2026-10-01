class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> mp;
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = make_pair(i, 1);
            }
            else{
                mp[s[i]].second++;
            }
        }
        int ans = INT_MAX;
        for(auto a : mp){
            if(a.second.second == 1){
                ans = min(ans, a.second.first);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};