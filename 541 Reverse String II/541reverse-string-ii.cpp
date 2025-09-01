class Solution {
public:
    string reverseStr(string s, int k) {
        if (s.length() < k) {
            int i = 0 ;
            int j = s.length() - 1;
            while(i<j){
                swap(s[i] , s[j]);
                i++;
                j--;
            }
            return s;
        }
        for(int i = 0 ; i < s.length() ; i+=2*k){
            int l = i;
            int j = i + k - 1;
            if (j <= s.length()){
                while(l<j){
                    swap(s[l] , s[j]);
                    l++;
                    j--;
                }
            }
            else {
                int j = s.length() - 1;
                while(i<j){
                    swap(s[i] , s[j]);
                    i++;
                    j--;
                }
            }
        }
        return s;
    }
    
};