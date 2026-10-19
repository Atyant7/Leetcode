class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        set<int, greater<int>> s;
        for (int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }
        if (s.size() < 3)
            return *s.begin();
        auto it = s.begin();
        advance(it, 2);
        return *it;
    }
};