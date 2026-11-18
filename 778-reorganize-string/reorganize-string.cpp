class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto a : mp){
            pq.push({a.second, a.first});
        }
        string ans = "";
        while(!pq.empty()){
            pair<int, char> temp = pq.top();
            pq.pop();
            ans += temp.second;
            temp.first--;
            if(!pq.empty()) {

                auto next = pq.top();
                pq.pop();

                ans += next.second;
                next.first--;

                if(next.first > 0) {
                    pq.push(next);
                }
            }

            if(temp.first > 0) {
                pq.push(temp);
            }
        }
        for(int i = 1; i < ans.size(); i++){
            if(ans[i] == ans[i-1]) return "";
        }
        return ans;
    }
};