class Solution {
public:
    int help(string ok) {
        int ans = 0;
        for (char c : ok) {
            ans += c - '0';
        }
        return ans;
    }
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(nums.begin(), nums.end());

        while (v.size() != 1) {
            vector<int> temp;
            for (int i = 1; i < v.size(); i++) {
                temp.push_back((v[i] + v[i - 1]) % 10);
            }
            v.clear();
            v = temp;
        }
        return v[0];
    }
};