class Solution {
public:
    int edgeScore(vector<int>& edges) {
        unordered_map<int, long long> mp;
        for(int i = 0; i < edges.size(); i++){
            mp[edges[i]] += i;
        }
        long long mx = INT_MIN;
        for(auto a : mp){
            mx = max(mx, a.second);
        }
        int ans = INT_MAX;
        for(auto a : mp){
            if(mx == a.second){
                ans = min(a.first, ans);
            }
        }
        return ans;
    }
};