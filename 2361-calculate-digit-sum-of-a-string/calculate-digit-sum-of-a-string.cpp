
class Solution {
public:
    int help(string ok) {
        int ans = 0;

        for (char c : ok) {
            ans += c - '0';
        }

        return ans;
    }

    string digitSum(string s, int k) {
        string ans = s;
        string sup = "";

        while (ans.size() > k) {
            for (int i = 0; i < ans.size(); i += k) {

                string temp = ans.substr(i, k);

                int a = help(temp);

                sup += to_string(a);
            }

            ans = sup;
            sup = "";
        }

        return ans;
    }
};
