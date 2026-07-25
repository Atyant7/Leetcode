class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        int m1 = 0;
        int m2 = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(m1 <= (s[i] - '0')){
                m2 = m1;
                m1 = s[i] - '0';
            }
            else if(m2 < (s[i] - '0') && m1 > (s[i] - '0')){
                m2 = s[i] - '0';
            }
        }
        return m1*m2;
        
    }
};