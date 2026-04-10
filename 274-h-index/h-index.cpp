class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 1;
        int n = citations.size();
        sort(citations.begin() , citations.end() , greater<int>());
        if(citations[0] == 0) return 0;
        for(int i = 0 ; i < n ; i++){
            if(citations[i] >= i+1){
                h = i + 1;
            }
            else{
                break;
            }
        }
        return h;
    }
};