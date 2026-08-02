class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> v;
        for(int i = 0 ; i < mat.size() ; i++){
            int ones = 0;
            for(int j = 0 ; j < mat[i].size() ; j++){
                if(mat[i][j] == 1) ones++;
            }
            v.push_back(make_pair(ones,i));
        }
        sort(v.begin() , v.end() , [](const pair<int, int> &a, const pair<int, int> &b){
            if(a.first == b.first) return a.second<b.second;
            return a.first<b.first;
        });
        vector<int> ans;
        for(int i = 0 ; i < k ; i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};