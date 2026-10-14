class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        while(true){
            int ok = min(9, sum);
            ans += char('0' + ok);
            sum -= ok;
            if(sum == 0) break;
        }
        
        if(ans.size() > num) return "";
        int temp = ans.size();
        for(int i = 0; i < num-temp; i++){
            ans+='0';
        }
        return ans;
    }
};