class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> ans;

        if(nums1.empty() || nums2.empty() || k == 0)
            return ans;


        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

        for(int i = 0 ; i < m & i < k; i++){
            pq.push({nums1[i] + nums2[0] ,{ i , 0}});
        }
        while(k-- > 0 && !pq.empty()){
            auto top = pq.top();
            pq.pop();
            ans.push_back({nums1[top.second.first],nums2[top.second.second]});
            if(top.second.second + 1 < n){
                pq.push({nums1[top.second.first] + nums2[top.second.second + 1] ,{ top.second.first , top.second.second + 1}});
            }
        }
        return ans;
    }
};