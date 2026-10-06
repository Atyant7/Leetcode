class Solution {
public:
    int minAddToMakeValid(string s) {
        int st1 = 0;
        stack<char> s1;
        for(int i = 0; i < s.size(); i++){
            if(!s1.empty() && s[i] == ')' && s1.top() == '('){
                s1.pop();
                continue;
            }
            s1.push(s[i]);
        }
        return s1.size();
    }
};