class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            if(s.size() == n/2){
                break;
            }
            s.insert(candyType[i]);
        }
        return s.size();
    }
};