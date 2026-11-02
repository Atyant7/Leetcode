class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto a : s){
            mp[a]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto [ch, freq] : mp){
            pq.push({freq, ch});
        }
        string ans = "";
        while(!pq.empty()){
            int freq = pq.top().first;
            char ch = pq.top().second;
            for(int i = 0; i < freq; i++){
                ans += ch;
            }
            pq.pop();
        }
        return ans;
    }
};