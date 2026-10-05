class Solution {
public:
    bool demo(string &s, string &t, int i, int j) {
        if(i == s.size())
            return true;

        if(j == t.size())
            return false;

        if(s[i] == t[j]) {
            return demo(s, t, i + 1, j + 1);
        }
        return demo(s, t, i, j + 1);
    }

    bool isSubsequence(string s, string t) {
        // return demo(s, t, 0, 0);
        if(s == "" && t == "") return true;
        int j = 0;
        for(int i = 0; i < t.size(); i++){
            if(s[j] == t[i]){
                j++;
            }
            if(j == s.size()){
                return true;
            }
        }
        return false;
    }
};