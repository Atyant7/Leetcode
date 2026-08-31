class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> all;
    vector<int> perm;
    vector<bool> available(n, true);

    queue<pair<vector<int>, vector<bool>>> bfsQ;
    bfsQ.push({perm, available}); // push at the back of the queue

    // dfs(nums, available, perm, all);

    while (!bfsQ.empty()) {
        perm = bfsQ.front().first;
        available = bfsQ.front().second;
        bfsQ.pop(); // pop from the front of the queue

        if (perm.size() == nums.size()) {
            all.push_back(perm);
        }
        else {
            for (int i = 0; i < nums.size(); i++) {
                if (available[i]) {
                    perm.push_back(nums[i]);
                    available[i] = false;

                    // dfs(nums, available, perm, all);
                    bfsQ.push({perm, available});
                    available[i] = true;
                    perm.pop_back();
                }
            }
        }
    }

    return all;
}
};