class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int> ans;
        int n = nums.size();
        // process the first window
        for(int i=0;i<k;i++){

            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);

        // Processing the rest of the window

        for(int i=k;i<n;i++){

            if(dq.front() == i-k){
                dq.pop_front();
            }

             while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);

            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};