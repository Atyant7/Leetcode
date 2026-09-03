class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(int i = s.size() - 1 ; i >= 0 ; i--){
            if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || (s[i]>= 48 && s[i] <= 57)){
                temp+=tolower(s[i]);
            }
        }
        string temp2 = temp;
        reverse(temp.begin() , temp.end());
        if(temp == temp2) return true;
        return false;
    }
};