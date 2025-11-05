class Solution {
public:
    string addStrings(string num1, string num2) {
        int a = num1.size() - 1;
    int b = num2.size() - 1;
    int carry = 0;
    string ans = "";

    while (a >= 0 || b >= 0 || carry) {
        int temp = carry;
        if (a >= 0) temp += num1[a--] - '0';
        if (b >= 0) temp += num2[b--] - '0';
        carry = temp / 10;
        ans += to_string(temp % 10);
    }

    reverse(ans.begin(), ans.end());
    return ans;
    }
};