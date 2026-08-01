class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt = 0;
        sort(word.begin(), word.end());
        for(int i = 0 ; i < word.size() ; i++){
            if(islower(word[i])) break;
            if(word.find(word[i] + 32) != string::npos && word[i + 1] != word[i]){
                cnt++;
            }
            
        }
        return cnt;
    }
};