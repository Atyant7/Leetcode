class Solution {
public:
    int maxProduct(vector<int>& arr) {
        // sort(nums.begin() , nums.end());
        int max1 = arr[0], max2 = INT_MIN;
        for (int i = 1; i < arr.size(); i++) {
            max2 = max(max2, min(arr[i], max1));
            max1 = max(max1, arr[i]);
        }
        // cout << max1 << "    " << max2;
        return (max1 - 1) * (max2 - 1);
    }
};