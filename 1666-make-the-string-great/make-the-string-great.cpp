class Solution {
public:
    string makeGood(string s) {
        if(s.size() <= 1) return s;
        int n = s.size();
        stack<char> st;
        st.push(s[n-1]);
        for(int i = n-2; i >= 0; i--){
            int flag = false;
            if(!st.empty() && (st.top() == s[i] + 32 || st.top() == s[i] - 32)){
                st.pop();
                flag = true;
            }
            if(!flag) st.push(s[i]);
            
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};