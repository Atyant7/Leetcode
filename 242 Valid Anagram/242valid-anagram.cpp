class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp;
        map<char,int> mp2;
        if(s.size() != t.size()) return false;
        for(auto pair : s){
            mp[pair]++;
        }
        for(auto pair : t){
            mp2[pair]++;
        }
        for (auto pair : mp){
            if(pair.second != mp2[pair.first]) return false ;
        }
        return true;

    }
};