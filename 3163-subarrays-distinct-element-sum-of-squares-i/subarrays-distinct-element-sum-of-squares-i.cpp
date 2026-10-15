class Solution {
public:
    int ans = 0;
    void generate(vector<int>& arr, int start, int end) {
        if (start == arr.size())
            return;

        if (end == arr.size()) {
            generate(arr, start + 1, start + 1);
            return;
        }
        set<int> s;
        for (int i = start; i <= end; i++) {
            s.insert(arr[i]);
        }
        ans += (s.size() * s.size());

        generate(arr, start, end + 1);
    }
    int sumCounts(vector<int>& nums) {
        vector<int> curr;
        generate(nums, 0, 0);
        return ans;
    }
};