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

        vector<tuple<int, int, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], addnum(nums[i]), i});
        }

        sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
            if (get<1>(a) == get<1>(b))
                return get<0>(a) < get<0>(b);

            return get<1>(a) < get<1>(b);
        });

        vector<pair<int, int>> ans(n);

        for (int i = 0; i < n; i++) {
            int originalIndex = get<2>(v[i]);
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