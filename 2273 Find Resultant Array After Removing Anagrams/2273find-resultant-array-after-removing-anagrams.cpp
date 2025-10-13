class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string prev = "";
        for (auto &w : words) {
            string temp = w;
            sort(temp.begin(), temp.end());
            if (temp != prev) {
                ans.push_back(w);
                prev = temp;
            }
        }
        return ans;
    }
};
