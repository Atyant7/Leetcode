class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> ps(n), ns(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
                ps[i] = -1;
            else
                ps[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
                ns[i] = n;
            else
                ns[i] = st.top();

            st.push(i);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int width = ns[i] - ps[i] - 1;
            ans = max(ans, width * heights[i]);
        }

        return ans;
    }
};