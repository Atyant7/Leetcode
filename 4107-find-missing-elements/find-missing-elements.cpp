class Solution {
public:
    int binarySearch(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target)
                return mid;

            if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<int> v;
        int minele = nums[0];
        int maxele = nums[nums.size()-1];
        for(int i = minele ; i <= maxele ; i++){
            int temp = binarySearch(nums, i);
            if(temp == -1){
                v.push_back(i);
            }
        }
        return v;
        
    }
};