class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> prefix(gain.size()+1);
        prefix[0] = 0;
        for(int i = 0 ; i < gain.size() ; i++){
            prefix[i+1] = prefix[i] + gain[i];
        }
        int max_alt = INT_MIN;
        for(auto a : prefix){
            max_alt = max(max_alt, a);
        }
        return max_alt;
    }
};