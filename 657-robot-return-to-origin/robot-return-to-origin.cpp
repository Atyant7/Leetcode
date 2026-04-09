class Solution {
public:
    bool judgeCircle(string moves) {
        map<char,int> mp;
        for(auto ss : moves){
            mp[ss]++;
        }
        if(mp['U'] == mp['D'] && mp['R'] == mp['L']) return true;
        return false;
    }
};