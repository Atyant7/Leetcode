class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1e9 + 7;
        long long sum = 0;
        long long right = 0;

        while (right < s.length()) {

            if (s[right] == '1') {

                long long left = right;

                while (right < s.length() && s[right] == '1')
                    right++;

                long long n = right - left;

                long long add = (n % MOD) * ((n + 1) % MOD) % MOD;
                add = add * ((MOD + 1) / 2) % MOD; // multiply by modular inverse of 2

                sum = (sum + add) % MOD;

            } else {
                right++;
            }
        }

        return sum % MOD;
    }
};
