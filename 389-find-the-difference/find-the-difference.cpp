class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> mp;
        for(int i = 0;i < s.size(); i++){
            mp[s[i]]++;
        }
        map<char, int> mp1;
        for(int i = 0; i < t.size(); i++){
            mp1[t[i]]++;
        }
        for(int i = 0; i < t.size(); i++){
            if(mp.find(t[i]) == mp.end()){
                return t[i];
            }
            else{
                if(mp[t[i]] != mp1[t[i]]){
                    return t[i];
                }
            }
        }
        return 'a';
    }
};