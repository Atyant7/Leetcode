class Solution {
public:
    int arrangeCoins(int n) {
        return floor((-1.0 + sqrt(1.0 + 8.0*n)) / 2.0);
    }
};