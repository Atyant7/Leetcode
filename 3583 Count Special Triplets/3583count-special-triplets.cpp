class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1000000007LL;
    int n = nums.size();
    if (n < 3) return 0;

    unordered_map<long long,long long> mp; 
    unordered_map<long long,long long> left; 

    for (int num : nums) mp[num]++;

    long long ans = 0;
    for (int j = 0; j < n; ++j) {
        long long val = nums[j];

        mp[val]--;
        if (mp[val] == 0) mp.erase(val);

        long long target = 2LL * val;  
        long long leftCount  = left.count(target) ? left[target]  : 0;
        long long rightCount = mp.count(target)   ? mp[target]   : 0;

        ans = (ans + (leftCount * rightCount) % MOD) % MOD;

        left[val]++;
    }

    return (int)ans; 
    }
};