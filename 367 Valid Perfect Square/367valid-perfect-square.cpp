class Solution {
public:
    bool isPerfectSquare(long long num) {
        if(num == 1) return true;
        long long st = 1 ;
        long long end = num/2;
        while(st <= end){
            long long mid = st + (end-st)/2;
            if(mid*mid == num) return true;
            else if(mid*mid > num) end = mid - 1;
            else st = mid + 1;
        }
        return false;
    }
};