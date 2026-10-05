class Solution {
public:
    string ok = "";
    void demo(string s, int i, int j, string t){
        if(i == t.size() || j > s.size()){
            return;
        }
        if(s[j] == t[i]){
            ok += t[i];
            j++;
        }
        demo(s, i+1, j, t);
    }
    bool isSubsequence(string s, string t) {
        demo(s, 0, 0, t);
        if(ok == s) return true;
        return false;
    }
};