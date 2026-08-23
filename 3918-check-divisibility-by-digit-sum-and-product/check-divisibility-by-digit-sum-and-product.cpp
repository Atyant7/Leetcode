class Solution {
public:
    bool checkDivisibility(int n) {
        int pro = 1;
        int sum = 0;
        int m = n;
        while(m > 0){
            int temp = m % 10;
            pro *= temp;
            sum += temp;
            m = m / 10;
        }
        if(n % (sum + pro) == 0) return true;
        return false;
    }
};