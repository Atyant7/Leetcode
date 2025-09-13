class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char , int> m;
        for(int i = 0 ; i < s.length() ; i++){
            m[s[i]]++;
        }
        int sum = 0;
        int max = 0;
        char ch;
        for(auto &i : m){
            if(i.second > max && (i.first == 'a' || i.first == 'e' || i.first == 'i' || i.first == 'o' || i.first == 'u')){
                max = i.second;
                ch = i.first;
            }  
        }
        sum = max;
        max = 0;
        for(auto &i : m){
            if(i.second > max && (i.first != 'a' && i.first != 'e' && i.first != 'i' && i.first != 'o' && i.first != 'u')){
                max = i.second;
                ch = i.first;
            }  
        }
        sum += max;
        return sum;
    }
};