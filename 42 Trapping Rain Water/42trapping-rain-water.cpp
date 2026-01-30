class Solution {
public:
    int trap(vector<int>& height) {
        // two pointer
        int ans = 0;
        int l = 0, r = height.size() - 1;
        int Lmax = 0, Rmax = 0;
        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] >= Lmax)
                    Lmax = height[l];
                else
                    ans += Lmax - height[l];
                l++;
            } else {
                if (height[r] >= Rmax)
                    Rmax = height[r];
                else
                    ans += Rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};