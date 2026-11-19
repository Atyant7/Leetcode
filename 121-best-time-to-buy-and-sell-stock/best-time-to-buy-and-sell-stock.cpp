class Solution {
public:
    // int f1(vector<int>& nums, int i){
        
    // }
    int maxProfit(vector<int>& prices) {
        stack<int> st;
        st.push(prices[0]);
        int ans = 0;
        for(int i = 1; i < prices.size(); i++){
            if(!st.empty() && st.top() < prices[i]){
                ans = max(ans, prices[i] - st.top());
                continue;
            }
            st.push(prices[i]);
        }
        return ans;
        // return f1(prices, 0);
    }
};