class Solution {
public:
    int minimumChairs(string s) {
        int chair = 0;
        int mx = 0;
        for(auto a : s){
            if(a == 'L'){
                chair--;
            }
            else{
                chair++;
            }
            
            mx = max(chair,mx);
        }
        return mx;
    }
};