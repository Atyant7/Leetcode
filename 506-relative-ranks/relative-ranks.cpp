class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        unordered_map<int, string> mp;
        vector<int> temp = score;
        sort(temp.begin(), temp.end(), greater<int>());
        int j = 1;
        for(int i = 0; i < n; i++){
            if(j == 1){
                mp[temp[i]] = "Gold Medal";
            }
            else if(j == 2){
                mp[temp[i]] = "Silver Medal";
            }
            else if(j == 3){
                mp[temp[i]] = "Bronze Medal";
            }
            else{
                mp[temp[i]] = to_string(j);
            }
            j++;
        }
        vector<string> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = mp[score[i]];
        }
        return ans;
    }
};