class Solution {
public:
    int reverseBits(int n) {
        string a = "";
        int ans = 0;
        while(n != 0){
            a += to_string(n%2);
            n = n / 2;
        }
        while(a.length() != 32){
            a+= '0';
        }
        int j = 0;
        for(int i = 31 ; i >= 0 ; i--){
            if(a[i] == '1'){
                ans += pow(2,j);
            }
            j++;
        }
        return ans;
    }
};