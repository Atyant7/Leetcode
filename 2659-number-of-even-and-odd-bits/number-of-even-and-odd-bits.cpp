class Solution {
public:
    vector<int> evenOddBit(int n) {
        string temp = "";
        while (n > 0) {
            temp+=to_string(n%2);
            n = n / 2;
        }
        int ev = 0;
        int od = 0;
        // reverse(temp.begin() , temp.end());
        for(int i = 0 ; i < temp.length() ; i++){
            if(temp[i] == '1'){
                if(i%2 == 0) ev++;
                else od++;
            }
        }
        return {ev,od};
    }
};