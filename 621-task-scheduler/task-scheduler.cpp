class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(int i = 0; i < tasks.size(); i++){
            mp[tasks[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto a : mp){
            pq.push({a.second, a.first});
        }
        int ans = 0;
        int m = n;
        while(!pq.empty()){
            vector<pair<int, char>> temp;

            int m = n + 1;

            while(m > 0 && !pq.empty()){

                auto curr = pq.top();
                pq.pop();

                curr.first--;

                if(curr.first > 0){
                    temp.push_back(curr);
                }

                ans++;
                m--;
            }

            // Push tasks back after completing the cooldown cycle
            for(auto a : temp){
                pq.push(a);
            }

            // Count idle time only if tasks are still remaining
            if(!pq.empty()){
                ans += m;
            }
        }
        return ans;
        
    }
};