class Solution {
public:
    int reverse(int x) {
        int temp = x;
        int res = 0;
        while(temp != 0){
            int d = temp % 10;
            if((res >= INT_MIN/10) && (res <= INT_MAX/10))
                res = res*10 + d;
            else return 0;
            temp = temp / 10;
        }
        if((res > pow(-2 , 31)) && (res < pow(2 , 31) - 1)) return res;
        return 0;
    }
};