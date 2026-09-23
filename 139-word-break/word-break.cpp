class Solution1 {
public:
    void dfs(string& s, unordered_set<string>& dict, int i, bool& all){
        if(i == s.size()){
            all = true;
        }
        else{
            for(int j = i; j < s.size(); j++){
                string word = s.substr(i, j-i+1);
                if(dict.find(word) != dict.end()){
                    dfs(s, dict, j+1, all);
                }
            }
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        bool all = false;
        string par;
        int i = 0;
        dfs(s, dict, i, all);
        return all;
    }
};

// head recursive
class Solution {
public:
    int f1(string& s, unordered_set<string>& dict, int i, vector<int> &F1){
        if(F1[i] != -1) return F1[i];
        if(i == s.size()){
            return F1[i] = 1;
        }
        else{
            int cnt = 0;
            for(int j = i; j < s.size(); j++){
                string word = s.substr(i, j-i+1);
                if(dict.find(word) != dict.end()){
                    cnt += f1(s, dict, j+1, F1);
                }
            }
            return F1[i] = cnt;
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int i = 0;
        vector<int> F1(s.size() + 1, -1);
        return f1(s, dict, i, F1) > 0;
    }
};