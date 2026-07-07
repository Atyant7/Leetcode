class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;
        string s = to_string(n);
        long long sum = 0;
        string x = "";
        for(auto a:s){
            if(a-'0' != 0){
                x = x + (a);
                sum = sum + (a - '0');
            }
        }
        return sum*(stoi(x));
    }
};