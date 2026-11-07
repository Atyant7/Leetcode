class Solution {
public:
    int bs(vector<int>& num, int start, int end, int tar){
        if(start > end){
            return -1;
        }
        int mid = start + (end - start)/2;
        if(num[mid] == tar){
            return mid;
        }
        if(num[mid] > tar){
            return bs(num, start, mid-1, tar);
        }
        return bs(num, mid+1, end, tar);
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        vector<int> ans;
        unordered_set<int> s;
        for(int i = 0; i < nums2.size(); i++){
            if(bs(nums1, 0, n-1, nums2[i]) != -1){
                s.insert(nums2[i]);
            }
        }
        for(auto a : s){
            ans.push_back(a);
        }
        return ans;
    }
};