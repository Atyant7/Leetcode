class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& coins, int amount) {
        vector<vector<int>> c;
        vector<int> p;
        int i = 0;
        dfs(coins, amount, i, c, p);
        return c;
    }

private:
    void dfs(vector<int>& coins, int t, int i,
             vector<vector<int>>& c, vector<int>& p) {

        if (t == 0)
            c.push_back(p);

        else if (i == coins.size()) {
        }

        else if (coins[i] > t) {
            dfs(coins, t, i + 1, c, p);
        }

        else {
            dfs(coins, t, i + 1, c, p);

            p.push_back(coins[i]);
            dfs(coins, t - coins[i], i, c, p);
            p.pop_back();
        }
    }
};