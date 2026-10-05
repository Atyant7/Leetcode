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
        return demo(s, t, 0, 0);
    }
};