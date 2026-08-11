class Solution {
public:
    int missingInteger(vector<int>& nums) {

        if(nums.size() == 1) {
            int ok = nums[0];

            while(true) {
                bool flag = false;

                for(int i = 0; i < nums.size(); i++) {
                    if(nums[i] == ok) {
                        flag = true;
                        break;
                    }
                }

                if(flag == false) {
                    return ok;
                }

                ok++;
            }
        }

        int sum = nums[0];

        // Find the sequential prefix
        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] == nums[i-1] + 1) {
                sum += nums[i];
            }
            else {
                break;
            }
        }

        int ok = sum;
        int ans = 0;

        while(ans == 0) {

            bool flag = false;

            for(int i = 0; i < nums.size(); i++) {

                if(nums[i] == ok) {
                    flag = true;
                    break;
                }
            }

            if(flag == false) {
                ans = ok;
            }

            ok++;
        }

        return ans;
    }
};