class Solution {
public:
    int distributeCandies(vector<int>& candy) {
        sort(candy.begin(), candy.end());
        int count=1, n=candy.size();
        for (int i=1; i<n; i++) {
            if (candy[i-1]!=candy[i]) count++;
        } if (count<=n/2) return count;
        else return n/2;

    }
};