class Solution {
public:
    int countGoodSubstrings(string s) {
        int cnt = 0 , j = 0;
        while(j < s.length()){
            string temp = s.substr(j , 3);
            if((count(temp.begin() , temp.end() , temp[0]) == 1) && (count(temp.begin() , temp.end() , temp[1]) == 1) && (count(temp.begin() , temp.end() , temp[2]) == 1)){
                cnt++;
            }
            j++;
        }
        return cnt;
    }
};