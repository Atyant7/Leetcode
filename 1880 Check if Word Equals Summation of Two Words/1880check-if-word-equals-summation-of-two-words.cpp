class Solution {
public:
    string fun(string s){
        int n = s.length();
        string ans = "";
        for(int i = 0 ; i < n ; i++){
            int a = s[i] - 97;
            ans += to_string(a);
        }
        return ans;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        string fw = fun(firstWord);
        string sw = fun(secondWord);
        string tw = fun(targetWord);
        if(stoi(fw) + stoi(sw) == stoi(tw)) return true;
        return false;

    }
};