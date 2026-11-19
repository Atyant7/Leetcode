class Solution {
public:
    int stackFunction(vector<int>& prices){
        stack<int> st;
        st.push(prices[0]);
        int ans = INT_MIN;
        for(int i = 1; i < prices.size(); i++){
            if(!st.empty() && st.top() < prices[i]){
                ans = max(ans, prices[i] - st.top());
                continue;
            }
            st.pop();
            st.push(prices[i]);
        }
        return ans;
    }
    int maximumDifference(vector<int>& nums) {
        int ans = stackFunction(nums);
        return ans < 0 ? -1 : ans;
    }
};