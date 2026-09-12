class Solution {
public:
    int digitsum(int n){
        int sum = 0;
        while(n > 0){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int addDigits(int num) {
        int sum = num;
        while( sum > 9){
            sum = digitsum(sum);
        }
        return sum;
    }
};