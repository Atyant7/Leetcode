// adaptation of the subset problem on leetcode
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> partialSubset;

        dfs(n, partialSubset, combinations, k);

        return combinations;
    }

private:
    void dfs(int n, vector<int>& partialSubset,
             vector<vector<int>>& combinations, int k) {

        if (0 == n) {
            if (partialSubset.size() == k)
                combinations.push_back(partialSubset);
        }
        else {
            // without n
            dfs(n - 1, partialSubset, combinations, k);

            // with n
            partialSubset.push_back(n);
            dfs(n - 1, partialSubset, combinations, k);
            partialSubset.pop_back();
        }
    }
};