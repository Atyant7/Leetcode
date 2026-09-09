class Solution {
public:
    int countDigit(long long n) {
        int cnt = 0;
        while (n > 0) {
            cnt++;
            n = n / 10;
        }
        return cnt;
    }

    long long countCommas(long long n) {
        if (n < 1000)
            return 0;
        long long ans = 0;
        if (countDigit(n) <= 6 && countDigit(n) > 3) {
            ans += n - 999;
        } else if (countDigit(n) <= 9 && countDigit(n) > 6) {
            ans += (n - 999) + (n - 999999);
        } else if (countDigit(n) <= 12 && countDigit(n) > 9) {
            ans += (n - 999) + (n - 999999) + (n - 999999999);
        } else if (countDigit(n) <= 16 && countDigit(n) > 12) {
            ans += (n - 999) + (n - 999999) + (n - 999999999) +
                   (n - 999999999999LL);
        } else if (countDigit(n) > 16) {
            ans += (n - 999) + (n - 999999) + (n - 999999999) +
                   (n - 999999999999LL) + (n - 999999999999999LL);
        }
        if(n == pow(10,15)) return ans+1;
        return ans;
    }
};