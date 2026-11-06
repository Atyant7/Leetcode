class Solution {
public:
    bool canMeasureWater(int jug1, int jug2, int target) {
        if (target == 0)
            return true;

        if (target > jug1 + jug2)
            return false;

        return target % gcd(jug1, jug2) == 0;
    }
};