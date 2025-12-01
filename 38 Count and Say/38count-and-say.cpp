class Solution {
public:
    string countAndSay(int n) {
        if (n==1) return "1";
        string ans = "1";
        for(int i = 2 ; i <= n ; i++){
            string temp = "";
            int len = 1;
            for(int j = 1 ; j < ans.length(); j++){
                if(ans[j] == ans[j-1]){
                    len++;
                }
                else{
                    temp += to_string(len) + ans[j - 1];
                    len = 1;
                }
            }
            temp += to_string(len) + ans.back();
            ans = temp;
        }
        return ans;
    }
};