class Solution {
public:
    int minimumPushes(string word) {
        int press = 0;
        for(int i = 0 ; i < word.size() ; i++){
            press += (i/8 + 1);
        }
        return press;
    }
};