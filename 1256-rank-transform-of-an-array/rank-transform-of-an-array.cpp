class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v(arr.size());
        for(int i = 0 ; i < arr.size() ; i++){
            v[i] = arr[i];
        }
        sort(v.begin(), v.end());
        unordered_map<int,int> mp;
        int rank = 1;
        for(int i = 0 ; i < v.size() ; i++){
            if(mp.find(v[i]) == mp.end()){
                mp[v[i]] = rank;
                rank++;
            }
        }
        for(int i = 0 ; i < arr.size() ; i++){
            v[i] = mp[arr[i]];
        }
        return v;
    }
};