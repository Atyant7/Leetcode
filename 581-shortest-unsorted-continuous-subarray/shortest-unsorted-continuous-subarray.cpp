class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> st;
        int lb = -1, rb = -1;

        st.push(0);

        for (int i = 1; i < nums.size(); i++) {
            while (!st.empty() && nums[i] < nums[st.top()]) {
                lb = (lb == -1) ? st.top() : min(lb, st.top());
                st.pop();
            }
            st.push(i);
        }

        if (lb == -1)
            return 0;

        while (!st.empty()) {
            st.pop();
        }

        st.push(nums.size() - 1);

        for (int i = nums.size() - 2; i >= 0; i--) {
            while (!st.empty() && nums[i] > nums[st.top()]) {
                rb = (rb == -1) ? st.top() : max(rb, st.top());
                st.pop();
            }
            st.push(i);
        }

        return rb - lb + 1;
    }
};