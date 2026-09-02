class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0) return {{}};

        // induction step
        int last_element = nums.back();
        nums.pop_back();
        vector<vector<int>> s1 = subsets(nums);  // powerset of n-1 element

        vector<vector<int>> s2;
        for(vector<int> subset : s1){
            subset.push_back(last_element);
            s2.push_back(subset);
        }

        vector<vector<int>> powerset = s1;
        powerset.insert(powerset.end(), s2.begin() , s2.end());
        return powerset;
    }
};