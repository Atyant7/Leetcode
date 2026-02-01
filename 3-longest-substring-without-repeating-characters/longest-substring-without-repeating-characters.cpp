class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>freq(256 , 0);
        int left = 0 , right = 0 , maxlen = 0 ;
        while(right < s.length()){
            freq[s[right]]++ ;

            while(freq[s[right]] > 1){
                freq[s[left]]--;
                left++;
            }
            maxlen = max(maxlen , right - left + 1);
            right++;
        }
        return maxlen;
    }
};