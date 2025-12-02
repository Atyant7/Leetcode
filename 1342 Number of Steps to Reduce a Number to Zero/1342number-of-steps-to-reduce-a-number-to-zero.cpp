class Solution {
public:
    int numberOfSteps(int num) {
        if(num == 0) return 0;
        int cnt = 0;
        while(num > 0){
            if((num & 1) == 0) cnt++;
            else cnt += 2;
            num = num >> 1;
        }
        return cnt - 1;
    }
};