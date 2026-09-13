class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans = INT_MIN;
        int n = img1.size();
        for(int i = -(n-1) ; i <= (n - 1); i++){
            for(int j = -(n-1) ; j <= (n-1) ; j++){
                int overlap = 0;
                for(int r = 0; r < n; r++){
                    for(int c = 0; c < n; c++){
                        int newr = r+i;
                        int newc = c+j;
                        if((newr < n && newr >= 0) && (newc < n && newc >= 0)){
                            if(img1[r][c] == 1 && img2[newr][newc] == 1){
                                overlap++;
                            }
                        }
                    }
                }
                ans = max(ans, overlap);
            }
        }
        return ans;
    }
};