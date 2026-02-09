class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1 && trust.size() == 0) return 1;
        vector<int> outd(n+1 , 0);
        vector<int> ind(n+1, 0);
        for(auto &t : trust){
            int a = t[0];
            int b = t[1];
            outd[a]++;
            ind[b]++;
        }
        for(int i = 0 ; i <= n ; i++){
            if(outd[i] == 0 && ind[i] == n-1) return i;
        }
        return -1;
    }
};