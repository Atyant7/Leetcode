class Solution {
public:
    int helper(vector<int> & v, int i, int j, vector<vector<int>> & ok){
        if( i == j) return v[i];
        if(ok[i][j] != -1){
            return ok[i][j];
        }
        int p1 = v[i] - helper(v, i+1, j, ok);
        int p2 = v[j] - helper(v, i, j-1, ok);
        return ok[i][j] = max(p1, p2);
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> ok(piles.size(), vector<int>(piles.size() , -1));
        int temp = helper(piles, 0, piles.size()-1, ok);
        return temp >= 0;
    }
};