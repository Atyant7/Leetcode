class Solution {
public: 
    int bs(vector<int>& nums, int target, int start, int end){
        if(start > end) return -1;
        int mid = start + (end - start)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] > target){
            return bs(nums, target, start, mid - 1);
        }
        return bs(nums, target, mid+1, end);
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] == target){
        //         ans.push_back(i);
        //     }
        //     if(nums[i] > target) break;
        // }

        int idx = bs(nums, target, 0, n-1);
        if(idx == -1) return {};
        int j = idx;
        while(j >= 0 && nums[j] == target){
            j--;
        while(idx < n && nums[idx] == target )
            idx++;
        }
        for(int i = j+1; i <= idx-1; i++){
            ans.push_back(i);
        }
        return ans;
    }
};