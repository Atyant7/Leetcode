class Solution {
public:
    int compress(vector<char>& chars) {
        // if(chars.size() == 1) return 1;
        int n = chars.size();
        string s = "";
        s += chars[0];
        int cnt = 1;
        char c = chars[0];
        for (int i = 1; i < n; i++) {
            if (chars[i] == c) {
                cnt++;
            } else {
                if (cnt == 1) {
                    s += chars[i];
                } else {
                    s += to_string(cnt);
                    s += chars[i];
                }
                cnt = 1;
                c = chars[i];
            }
        }
        if(cnt != 1){
            s+=to_string(cnt);
        }
        chars.clear();
        for (auto a : s) {
            chars.push_back(a);
        }
        return s.length();
    }
};