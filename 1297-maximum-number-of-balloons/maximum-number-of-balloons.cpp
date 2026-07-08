class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char , int> mp;
        for(auto a : text){
            mp[a]++;
        }
        return min({mp['a'] , mp['b'] , mp['n'] , mp['l']/2 , mp['o']/2});

    }
};