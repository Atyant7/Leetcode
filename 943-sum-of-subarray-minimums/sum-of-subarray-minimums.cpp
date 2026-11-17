class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Smaller Element
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next Smaller Element
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        // Calculate contribution
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long contribution =
                (1LL * arr[i] * left[i] * right[i]) % MOD;
            ans = (ans + contribution) % MOD;
        }
        return ans;
    }
};