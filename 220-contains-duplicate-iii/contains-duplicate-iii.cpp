class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {

        set<long long> st;

        for (int i = 0; i < nums.size(); i++) {

            set<long long>::iterator it =
                st.lower_bound((long long)nums[i] - valueDiff);

            if (it != st.end()) {

                long long x = *it;

                if (x - nums[i] <= valueDiff)
                    return true;
            }

            st.insert(nums[i]);

            if (i >= indexDiff)
                st.erase(nums[i - indexDiff]);
        }

        return false;
    }
};