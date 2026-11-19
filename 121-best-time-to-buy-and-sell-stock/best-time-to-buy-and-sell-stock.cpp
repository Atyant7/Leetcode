class Solution {
public:
    int stackFunction(vector<int>& prices){
        stack<int> st;
        st.push(prices[0]);
        int ans = 0;
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
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        for(int price : prices){
            min_price = min(min_price, price);
            max_profit = max(max_profit, price - min_price);
        }
        return max_profit;
    }
};