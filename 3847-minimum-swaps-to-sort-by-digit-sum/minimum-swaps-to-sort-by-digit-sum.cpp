class Solution {
public:
    int addnum(int num) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    void dfs(int node, vector<pair<int, int>>& ans,
             vector<bool>& visited) {
        visited[node] = true;

        int next = ans[node].second;

        if (!visited[next]) {
            dfs(next, ans, visited);
        }
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<pair<int, int>, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({{nums[i], addnum(nums[i])}, i});
        }

        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            if (a.first.second == b.first.second)
                return a.first.first < b.first.first;

            return a.first.second < b.first.second;
        });

        vector<pair<int, int>> ans(n);

        for (int i = 0; i < n; i++) {
            int originalIndex = v[i].second;
            ans[originalIndex] = {nums[originalIndex], i};
        }

        vector<bool> visited(n, false);
        int cycles = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cycles++;
                dfs(i, ans, visited);
            }
        }

        return n - cycles;
    }
};