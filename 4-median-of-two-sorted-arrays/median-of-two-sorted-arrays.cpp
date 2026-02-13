class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int i = 0 , j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }
            else{
                v.push_back(nums2[j]);
                j++;
            }
        }
        while(i < nums1.size()){
            v.push_back(nums1[i]);
            i++;
        }
        while(j < nums2.size()){
            v.push_back(nums2[j]);
            j++;
        }
        int n = v.size();
        double d = 0;
        if(n % 2 == 0){
            int mid = int(n/2);
            d = (v[mid] + v[mid-1])/2.0;
        }
        else{
            int mid = int(n/2);
            d = v[mid];
        }
        return d;
    }
};