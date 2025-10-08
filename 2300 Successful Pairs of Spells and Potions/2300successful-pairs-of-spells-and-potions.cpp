class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        long long sp = spells.size();
        long long po = potions.size() - 1;
        sort(potions.begin() , potions.end());
        long long stpo;
        for(long long i = 0 ; i < sp ; i++){
            long long count = 0;
            stpo = 0;
            long long end = po;
            while(stpo <= end){
                long long midpo = stpo + (end - stpo)/2;
                if((long long)spells[i]*potions[midpo] >= success){
                    end = midpo - 1;
                }
                else {
                    stpo = midpo + 1;
                }
            }
            ans.push_back(po - end);
        }
        return ans;
    }
};