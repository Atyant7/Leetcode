class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> pq;
        for(int i = 0; i < gifts.size(); i++){
            pq.push(gifts[i]);
        }
        while(k--){
            long long temp = pq.top();
            pq.pop();
            pq.push(sqrt(temp));
        }
        long long ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};