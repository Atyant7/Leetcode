class Solution {
public:
    string sortVowels(string s) {
        vector<char> v;
        for (int i = 0 ; i < s.length() ; i++){
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                v.push_back(s[i]);
                s[i] = '#';
            }
        }
        sort(v.begin()  , v.end());
        int a = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '#'){
                s[i] = v[a];
                a++;
            }
        }
        return s;
    }
};