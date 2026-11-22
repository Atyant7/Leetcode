class Solution {
public:
    bool checkString(string s) {
        bool flagb = false;
        for(char ch : s){
            if(ch == 'b') flagb = true;
            if(flagb && ch == 'a') return false;
        }
        return true;
    }
};