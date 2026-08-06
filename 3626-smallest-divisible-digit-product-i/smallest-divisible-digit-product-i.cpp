class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans = n;
        int m = n;
        while(m){
            int ok = m;
            int rep = 1;
            while(ok > 0){
                rep = rep * (ok%10);
                ok = ok / 10;
            }
            if(rep % t == 0){
                ans = m;
                break;
            }else{
                m++;
            }
        }
        return ans;
    }
};