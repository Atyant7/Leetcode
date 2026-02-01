class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_vol = 0;
        int left = 0;
        int right = height.size() - 1;
        while(left <= right){
            int min_vol = min(height[left] , height[right])*(right - left);
            max_vol = max(max_vol , min_vol);
            if(height[left] <= height[right]) left++;
            else right--;
        }
        return max_vol;
    }
};