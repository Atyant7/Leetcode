class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26, 0);
        for(int i = 0 ; i < word.size() ; i++){
            v[word[i] - 'a']++;
        }
        sort(v.begin() , v.end() , greater<int>());
        int press = 0;
        for(int i = 0 ;i < v.size() ; i++){
            press += (i/8 + 1)*v[i];
        }
        return press;
    }
};