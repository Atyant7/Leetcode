class Solution {
public:
    int maxBottlesDrunk(int n, int x) {
        int d = 0 ;
        while(n >= x){
            d += x;
            n -= x;
            n++;
            x++;
        }
        return d + n;
    }
};