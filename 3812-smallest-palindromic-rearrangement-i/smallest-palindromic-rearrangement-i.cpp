class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if( n == 1 || n == 3) return s;
        if(n%2 == 0){
            int mid = n / 2;
            sort(s.begin() , s.begin()+mid);
            sort(s.begin() + mid , s.end() , greater<int>());
        }
        else{
            int mid = (n)/2;
            sort(s.begin() , s.begin() + mid);
            sort(s.begin() + mid + 1 , s.end(), greater<int>());
        }
        return s;
    }
};