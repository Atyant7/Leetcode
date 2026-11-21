
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int> st;
        vector<int> ans;

        for(int x : nums) {
            if(st.count(x))
                ans.push_back(x);
            else
                st.insert(x);
        }

        return ans;
    }
};
