class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> li(n);
        vector<int> ri(n);

        for (int i = 0; i < n; i++) {
            li[i] = intervals[i][0];
            ri[i] = intervals[i][1];
        }

        int j = 0;

        for (int k = 0; k < n; k++) {
            bool covered = false;

            for (int i = 0; i < n; i++) {

                if (k == i) continue;

                if (li[i] <= li[k] && ri[i] >= ri[k]) {
                    covered = true;
                    break;
                }
            }

            if (covered)
                j++;
        }

        return n - j;
    }
};