class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int sum = 0;
            int cnt = 0;
            if (k > 0) {
                int j = (i + 1) % n;
                while (i != j && cnt < k) {
                    sum += code[j];
                    j = (j + 1) % n;
                    cnt++;
                }
            } else if (k < 0) {
                int j = (i - 1 + n) % n;
                while (cnt < -k) {
                    sum += code[j];
                    cnt++;
                    j = (j - 1 + n) % n;
                }
            }
            ans[i] = sum;
        }
        return ans;
    }
};