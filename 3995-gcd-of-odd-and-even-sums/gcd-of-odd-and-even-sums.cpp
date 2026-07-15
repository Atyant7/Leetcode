class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b,a%b);
    }
    int gcdOfOddEvenSums(int n) {
        int odd = 0, even = 0;
        for(int i = 1 ; i <= 2*n ; i++){
            if(i % 2 == 0){
                even = even + i;
            }
            else{
                odd = odd + i;
            }
        }
        return gcd(odd, even);
    }
};