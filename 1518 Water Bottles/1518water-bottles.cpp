class Solution {
public:
    int numWaterBottles(int n, int x) {
        if(n == x) return n + 1;
        else if(n < x) return n;
        return n + (n/x) + 1;
    }
};