class Solution {
public:
    int helper(string s){
        int ans = 0;
        for(auto a : s){
            if(a == ' '){
                ans++;
            }
        }
        return ++ans;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = messages.size();
        vector<string> v;
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++){
            mp[senders[i]] += helper(messages[i]);
        }
        priority_queue<pair<int, string>> pq;
        for(auto [a, freq] : mp){
            pq.push({freq, a});
        }
        return pq.top().second;
    }
};