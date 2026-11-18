class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        st.push(stoi(operations[0]));
        int i = 1;
        int record = stoi(operations[0]);
        while (i < operations.size()) {
            if (operations[i] == "C") {
                st.pop();
            } else if (operations[i] == "D") {
                int temp = st.top();
                st.push(temp * 2);
            } else if (operations[i] == "+") {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                st.push(b);
                st.push(a);

                st.push(a + b);
            } else {
                st.push(stoi(operations[i]));
            }
            i++;
        }
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};