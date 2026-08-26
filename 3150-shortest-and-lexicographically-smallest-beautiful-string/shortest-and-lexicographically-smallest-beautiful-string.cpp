class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        if(k == 1){
            for(int i = 0 ; i < s.length() ; i++){
                if(s[i] == '1') return "1";
            }
            return "";
        }
        vector<string> v;
        int temp = k;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                temp--;
                for (int j = i + 1; j < s.length(); j++) {
                    if (s[j] == '1') {
                        temp--;
                        if (temp == 0) {
                            v.push_back(s.substr(i, j - i + 1));
                            temp = k;
                            break;
                        }
                    }
                }
                temp = k;
            }
        }
        sort(v.begin(), v.end(), [](const string& a, const string& b) {
            if (a.length() != b.length())
                return a.length() < b.length();

            return a < b;
        });
        if (v.empty())
            return "";
        return v[0];
    }
};