class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int ans = 0;
        for(auto a : piles){
            pq.push(a);
            ans += a;
        }

        while(k--){
            int x = pq.top();
            pq.pop();
            ans -= x/2;
            pq.push(x - x/2);
        }
        
        return ans;
    }
};