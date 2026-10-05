class Solution {
public:
    bool demo(string& s, string &t, int i, int j) {
        if(i == s.size())
            return true;

        if(j == t.size())
            return false;

        if(s[i] == t[j]) {
            return demo(s, t, i + 1, j + 1);
        }
        return demo(s, t, i, j + 1);
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        unordered_map<string , int> mp;
        for(int i = 0; i < words.size(); i++){
            mp[words[i]]++;
        }
        for(auto& m : mp){
            string temp = m.first;
            if(demo(temp, s, 0, 0)){
                ans+=m.second;
            }
        }
        return ans;
    }
};