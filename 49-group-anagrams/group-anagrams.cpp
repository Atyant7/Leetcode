class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        unordered_map<string, vector<string>> m;  // map sorted string -> list of anagrams
    
    for (auto &s : strs) {
        string temp = s;
        sort(temp.begin(), temp.end());  // sorted string as key
        m[temp].push_back(s);            // push into correct group
    }

    vector<vector<string>> ans;
    for (auto &p : m) {
        ans.push_back(p.second);
    }
    return ans;
    }
};